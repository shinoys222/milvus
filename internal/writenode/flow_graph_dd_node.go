package writenode

import (
	"log"
	"sort"

	"github.com/golang/protobuf/proto"

	"github.com/zilliztech/milvus-distributed/internal/msgstream"
	internalPb "github.com/zilliztech/milvus-distributed/internal/proto/internalpb"
	"github.com/zilliztech/milvus-distributed/internal/proto/schemapb"
)

type ddNode struct {
	BaseNode
	ddMsg    *ddMsg
	ddBuffer *ddBuffer
}

func (ddNode *ddNode) Name() string {
	return "ddNode"
}

func (ddNode *ddNode) Operate(in []*Msg) []*Msg {
	//fmt.Println("Do filterDmNode operation")

	if len(in) != 1 {
		log.Println("Invalid operate message input in ddNode, input length = ", len(in))
		// TODO: add error handling
	}

	msMsg, ok := (*in[0]).(*MsgStreamMsg)
	if !ok {
		log.Println("type assertion failed for MsgStreamMsg")
		// TODO: add error handling
	}

	var ddMsg = ddMsg{
		collectionRecords: make(map[string][]metaOperateRecord),
		partitionRecords:  make(map[string][]metaOperateRecord),
		timeRange: TimeRange{
			timestampMin: msMsg.TimestampMin(),
			timestampMax: msMsg.TimestampMax(),
		},
	}
	ddNode.ddMsg = &ddMsg

	// sort tsMessages
	tsMessages := msMsg.TsMessages()
	sort.Slice(tsMessages,
		func(i, j int) bool {
			return tsMessages[i].BeginTs() < tsMessages[j].BeginTs()
		})

	// do dd tasks
	for _, msg := range tsMessages {
		switch msg.Type() {
		case internalPb.MsgType_kCreateCollection:
			ddNode.createCollection(msg.(*msgstream.CreateCollectionMsg))
		case internalPb.MsgType_kDropCollection:
			ddNode.dropCollection(msg.(*msgstream.DropCollectionMsg))
		case internalPb.MsgType_kCreatePartition:
			ddNode.createPartition(msg.(*msgstream.CreatePartitionMsg))
		case internalPb.MsgType_kDropPartition:
			ddNode.dropPartition(msg.(*msgstream.DropPartitionMsg))
		default:
			log.Println("Non supporting message type:", msg.Type())
		}
	}

	var res Msg = ddNode.ddMsg
	return []*Msg{&res}
}

func (ddNode *ddNode) createCollection(msg *msgstream.CreateCollectionMsg) {
	collectionID := msg.CollectionID

	err := ddNode.ddBuffer.addCollection(collectionID)
	if err != nil {
		log.Println(err)
		return
	}

	// TODO: add default partition?

	var schema schemapb.CollectionSchema
	err = proto.Unmarshal((*msg.Schema).Value, &schema)
	if err != nil {
		log.Println(err)
		return
	}
	collectionName := schema.Name
	ddNode.ddMsg.collectionRecords[collectionName] = append(ddNode.ddMsg.collectionRecords[collectionName],
		metaOperateRecord{
			createOrDrop: true,
			timestamp:    msg.Timestamp,
		})

	// TODO: write dd binlog
}

func (ddNode *ddNode) dropCollection(msg *msgstream.DropCollectionMsg) {
	collectionID := msg.CollectionID

	err := ddNode.ddBuffer.removeCollection(collectionID)
	if err != nil {
		log.Println(err)
		return
	}

	collectionName := msg.CollectionName.CollectionName
	ddNode.ddMsg.collectionRecords[collectionName] = append(ddNode.ddMsg.collectionRecords[collectionName],
		metaOperateRecord{
			createOrDrop: false,
			timestamp:    msg.Timestamp,
		})

	// TODO: write dd binlog
}

func (ddNode *ddNode) createPartition(msg *msgstream.CreatePartitionMsg) {
	partitionID := msg.PartitionID

	err := ddNode.ddBuffer.addPartition(partitionID)
	if err != nil {
		log.Println(err)
		return
	}

	partitionTag := msg.PartitionName.Tag
	ddNode.ddMsg.partitionRecords[partitionTag] = append(ddNode.ddMsg.partitionRecords[partitionTag],
		metaOperateRecord{
			createOrDrop: true,
			timestamp:    msg.Timestamp,
		})

	// TODO: write dd binlog
}

func (ddNode *ddNode) dropPartition(msg *msgstream.DropPartitionMsg) {
	partitionID := msg.PartitionID

	err := ddNode.ddBuffer.removePartition(partitionID)
	if err != nil {
		log.Println(err)
		return
	}

	partitionTag := msg.PartitionName.Tag
	ddNode.ddMsg.partitionRecords[partitionTag] = append(ddNode.ddMsg.partitionRecords[partitionTag],
		metaOperateRecord{
			createOrDrop: false,
			timestamp:    msg.Timestamp,
		})

	// TODO: write dd binlog
}

func newDDNode() *ddNode {
	maxQueueLength := Params.FlowGraphMaxQueueLength
	maxParallelism := Params.FlowGraphMaxParallelism

	baseNode := BaseNode{}
	baseNode.SetMaxQueueLength(maxQueueLength)
	baseNode.SetMaxParallelism(maxParallelism)

	ddBuffer := &ddBuffer{
		collectionBuffer: make(map[UniqueID]interface{}),
		partitionBuffer:  make(map[UniqueID]interface{}),
	}

	return &ddNode{
		BaseNode: baseNode,
		ddBuffer: ddBuffer,
	}
}