package master

import (
	"context"
	"time"

	"github.com/zilliztech/milvus-distributed/internal/errors"
	"github.com/zilliztech/milvus-distributed/internal/master/id"
	"github.com/zilliztech/milvus-distributed/internal/master/tso"
	"github.com/zilliztech/milvus-distributed/internal/proto/commonpb"
	"github.com/zilliztech/milvus-distributed/internal/proto/internalpb"
	"github.com/zilliztech/milvus-distributed/internal/proto/servicepb"
)

const slowThreshold = 5 * time.Millisecond

func (s *Master) CreateCollection(ctx context.Context, in *internalpb.CreateCollectionRequest) (*commonpb.Status, error) {
	var t task = &createCollectionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "Enqueue failed",
		}, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "create collection failed",
		}, nil
	}

	return &commonpb.Status{
		ErrorCode: commonpb.ErrorCode_SUCCESS,
	}, nil
}

func (s *Master) DropCollection(ctx context.Context, in *internalpb.DropCollectionRequest) (*commonpb.Status, error) {
	var t task = &dropCollectionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "Enqueue failed",
		}, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "WaitToFinish failed",
		}, nil
	}

	return &commonpb.Status{
		ErrorCode: commonpb.ErrorCode_SUCCESS,
	}, nil
}

func (s *Master) HasCollection(ctx context.Context, in *internalpb.HasCollectionRequest) (*servicepb.BoolResponse, error) {
	var t task = &hasCollectionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
		hasCollection: false,
	}

	st := &commonpb.Status{
		ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
	}

	response := &servicepb.BoolResponse{
		Status: st,
		Value:  false,
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		st.Reason = "Enqueue failed"
		return response, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		st.Reason = "WaitToFinish failed"
		return response, nil
	}

	st.ErrorCode = commonpb.ErrorCode_SUCCESS
	response.Value = t.(*hasCollectionTask).hasCollection
	return response, nil
}

func (s *Master) DescribeCollection(ctx context.Context, in *internalpb.DescribeCollectionRequest) (*servicepb.CollectionDescription, error) {
	var t task = &describeCollectionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
		description: nil,
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		err := errors.New("Enqueue failed")
		return t.(*describeCollectionTask).description, err
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		err := errors.New("WaitToFinish failed")
		return t.(*describeCollectionTask).description, err
	}

	return t.(*describeCollectionTask).description, nil
}

func (s *Master) ShowCollections(ctx context.Context, in *internalpb.ShowCollectionRequest) (*servicepb.StringListResponse, error) {
	var t task = &showCollectionsTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
		stringListResponse: nil,
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		err := errors.New("Enqueue failed")
		return t.(*showCollectionsTask).stringListResponse, err
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		err := errors.New("WaitToFinish failed")
		return t.(*showCollectionsTask).stringListResponse, err
	}

	return t.(*showCollectionsTask).stringListResponse, nil
}

//////////////////////////////////////////////////////////////////////////
func (s *Master) CreatePartition(ctx context.Context, in *internalpb.CreatePartitionRequest) (*commonpb.Status, error) {
	var t task = &createPartitionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "Enqueue failed",
		}, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "WaitToFinish failed",
		}, nil
	}

	return &commonpb.Status{
		ErrorCode: commonpb.ErrorCode_SUCCESS,
	}, nil
}

func (s *Master) DropPartition(ctx context.Context, in *internalpb.DropPartitionRequest) (*commonpb.Status, error) {
	var t task = &dropPartitionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "Enqueue failed",
		}, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		return &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
			Reason:    "WaitToFinish failed",
		}, nil
	}

	return &commonpb.Status{
		ErrorCode: commonpb.ErrorCode_SUCCESS,
	}, nil
}

func (s *Master) HasPartition(ctx context.Context, in *internalpb.HasPartitionRequest) (*servicepb.BoolResponse, error) {
	var t task = &hasPartitionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
		hasPartition: false,
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		return &servicepb.BoolResponse{
			Status: &commonpb.Status{
				ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
				Reason:    "Enqueue failed",
			},
			Value: t.(*hasPartitionTask).hasPartition,
		}, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		return &servicepb.BoolResponse{
			Status: &commonpb.Status{
				ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
				Reason:    "WaitToFinish failed",
			},
			Value: t.(*hasPartitionTask).hasPartition,
		}, nil
	}

	return &servicepb.BoolResponse{
		Status: &commonpb.Status{
			ErrorCode: commonpb.ErrorCode_SUCCESS,
		},
		Value: t.(*hasPartitionTask).hasPartition,
	}, nil
}

func (s *Master) DescribePartition(ctx context.Context, in *internalpb.DescribePartitionRequest) (*servicepb.PartitionDescription, error) {
	var t task = &describePartitionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
		description: nil,
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		return &servicepb.PartitionDescription{
			Status: &commonpb.Status{
				ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
				Reason:    "Enqueue failed",
			},
			Name:       in.PartitionName,
			Statistics: nil,
		}, nil
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		return &servicepb.PartitionDescription{
			Status: &commonpb.Status{
				ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR,
				Reason:    "WaitToFinish failed",
			},
			Name:       in.PartitionName,
			Statistics: nil,
		}, nil
	}

	return t.(*describePartitionTask).description, nil
}

func (s *Master) ShowPartitions(ctx context.Context, in *internalpb.ShowPartitionRequest) (*servicepb.StringListResponse, error) {
	var t task = &showPartitionTask{
		req: in,
		baseTask: baseTask{
			kvBase: s.kvBase,
			mt:     s.mt,
			cv:     make(chan error),
		},
		stringListResponse: nil,
	}

	var err = s.scheduler.Enqueue(t)
	if err != nil {
		err := errors.New("Enqueue failed")
		return t.(*showPartitionTask).stringListResponse, err
	}

	err = t.WaitToFinish(ctx)
	if err != nil {
		err := errors.New("WaitToFinish failed")
		return t.(*showPartitionTask).stringListResponse, err
	}

	return t.(*showPartitionTask).stringListResponse, nil
}

//----------------------------------------Internal GRPC Service--------------------------------

func (s *Master) AllocTimestamp(ctx context.Context, request *internalpb.TsoRequest) (*internalpb.TsoResponse, error) {
	count := request.GetCount()
	ts, err := tso.Alloc(count)

	if err != nil {
		return &internalpb.TsoResponse{
			Status: &commonpb.Status{ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR},
		}, err
	}

	response := &internalpb.TsoResponse{
		Status:    &commonpb.Status{ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR},
		Timestamp: ts,
		Count:     count,
	}

	return response, nil
}

func (s *Master) AllocID(ctx context.Context, request *internalpb.IDRequest) (*internalpb.IDResponse, error) {
	count := request.GetCount()
	ts, err := id.AllocOne()

	if err != nil {
		return &internalpb.IDResponse{
			Status: &commonpb.Status{ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR},
		}, err
	}

	response := &internalpb.IDResponse{
		Status: &commonpb.Status{ErrorCode: commonpb.ErrorCode_UNEXPECTED_ERROR},
		ID:     ts,
		Count:  count,
	}

	return response, nil
}