package querynode

import (
	"context"
	"fmt"
	"log"
	"strconv"
	"time"

	"github.com/zilliztech/milvus-distributed/internal/msgstream"
	"github.com/zilliztech/milvus-distributed/internal/proto/internalpb"
)

type statsService struct {
	ctx         context.Context
	statsStream msgstream.MsgStream
	replica     collectionReplica
}

func newStatsService(ctx context.Context, replica collectionReplica) *statsService {

	return &statsService{
		ctx:         ctx,
		statsStream: nil,
		replica:     replica,
	}
}

func (sService *statsService) start() {
	sleepTimeInterval := Params.StatsPublishInterval
	receiveBufSize := Params.StatsReceiveBufSize

	// start pulsar
	msgStreamURL := Params.PulsarAddress
	producerChannels := []string{Params.StatsChannelName}

	statsStream := msgstream.NewPulsarMsgStream(sService.ctx, receiveBufSize)
	statsStream.SetPulsarClient(msgStreamURL)
	statsStream.CreatePulsarProducers(producerChannels)

	var statsMsgStream msgstream.MsgStream = statsStream

	sService.statsStream = statsMsgStream
	sService.statsStream.Start()

	// start service
	fmt.Println("do segments statistic in ", strconv.Itoa(sleepTimeInterval), "ms")
	for {
		select {
		case <-sService.ctx.Done():
			return
		case <-time.After(time.Duration(sleepTimeInterval) * time.Millisecond):
			sService.sendSegmentStatistic()
		}
	}
}

func (sService *statsService) close() {
	if sService.statsStream != nil {
		sService.statsStream.Close()
	}
}

func (sService *statsService) sendSegmentStatistic() {
	statisticData := sService.replica.getSegmentStatistics()

	// fmt.Println("Publish segment statistic")
	// fmt.Println(statisticData)
	sService.publicStatistic(statisticData)
}

func (sService *statsService) publicStatistic(statistic *internalpb.QueryNodeStats) {
	var msg msgstream.TsMsg = &msgstream.QueryNodeStatsMsg{
		BaseMsg: msgstream.BaseMsg{
			HashValues: []uint32{0},
		},
		QueryNodeStats: *statistic,
	}

	var msgPack = msgstream.MsgPack{
		Msgs: []msgstream.TsMsg{msg},
	}
	err := sService.statsStream.Produce(&msgPack)
	if err != nil {
		log.Println(err)
	}
}