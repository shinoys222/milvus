// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: etcd.proto
#ifndef GRPC_etcd_2eproto__INCLUDED
#define GRPC_etcd_2eproto__INCLUDED

#include "etcd.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc_impl {
class CompletionQueue;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc_impl

namespace grpc {
namespace experimental {
template <typename RequestT, typename ResponseT>
class MessageAllocator;
}  // namespace experimental
}  // namespace grpc

namespace etcdserverpb {

class Watch final {
 public:
  static constexpr char const* service_full_name() {
    return "etcdserverpb.Watch";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Watch watches for events happening or that have happened. Both input and output
    // are streams; the input stream is for creating and canceling watchers and the output
    // stream sends events. One watch RPC can watch on multiple key ranges, streaming events
    // for several watches at once. The entire event history can be watched starting from the
    // last compaction revision.
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>> Watch(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>>(WatchRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>> AsyncWatch(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>>(AsyncWatchRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>> PrepareAsyncWatch(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>>(PrepareAsyncWatchRaw(context, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // Watch watches for events happening or that have happened. Both input and output
      // are streams; the input stream is for creating and canceling watchers and the output
      // stream sends events. One watch RPC can watch on multiple key ranges, streaming events
      // for several watches at once. The entire event history can be watched starting from the
      // last compaction revision.
      virtual void Watch(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::etcdserverpb::WatchRequest,::etcdserverpb::WatchResponse>* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* WatchRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* AsyncWatchRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* PrepareAsyncWatchRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>> Watch(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>>(WatchRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>> AsyncWatch(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>>(AsyncWatchRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>> PrepareAsyncWatch(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>>(PrepareAsyncWatchRaw(context, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Watch(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::etcdserverpb::WatchRequest,::etcdserverpb::WatchResponse>* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* WatchRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* AsyncWatchRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* PrepareAsyncWatchRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Watch_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Watch watches for events happening or that have happened. Both input and output
    // are streams; the input stream is for creating and canceling watchers and the output
    // stream sends events. One watch RPC can watch on multiple key ranges, streaming events
    // for several watches at once. The entire event history can be watched starting from the
    // last compaction revision.
    virtual ::grpc::Status Watch(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_Watch : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Watch() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Watch() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Watch(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestWatch(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Watch<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Watch : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Watch() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc_impl::internal::CallbackBidiHandler< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>(
          [this] { return this->Watch(); }));
    }
    ~ExperimentalWithCallbackMethod_Watch() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Watch(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::experimental::ServerBidiReactor< ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>* Watch() {
      return new ::grpc_impl::internal::UnimplementedBidiReactor<
        ::etcdserverpb::WatchRequest, ::etcdserverpb::WatchResponse>;}
  };
  typedef ExperimentalWithCallbackMethod_Watch<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Watch : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Watch() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Watch() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Watch(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Watch : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Watch() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Watch() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Watch(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestWatch(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Watch : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Watch() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc_impl::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this] { return this->Watch(); }));
    }
    ~ExperimentalWithRawCallbackMethod_Watch() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Watch(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::etcdserverpb::WatchResponse, ::etcdserverpb::WatchRequest>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::experimental::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* Watch() {
      return new ::grpc_impl::internal::UnimplementedBidiReactor<
        ::grpc::ByteBuffer, ::grpc::ByteBuffer>;}
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

class KV final {
 public:
  static constexpr char const* service_full_name() {
    return "etcdserverpb.KV";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Range gets the keys in the range from the key-value store.
    virtual ::grpc::Status Range(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::etcdserverpb::RangeResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::etcdserverpb::RangeResponse>> AsyncRange(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::etcdserverpb::RangeResponse>>(AsyncRangeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::etcdserverpb::RangeResponse>> PrepareAsyncRange(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::etcdserverpb::RangeResponse>>(PrepareAsyncRangeRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // Range gets the keys in the range from the key-value store.
      virtual void Range(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest* request, ::etcdserverpb::RangeResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Range(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::etcdserverpb::RangeResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Range(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest* request, ::etcdserverpb::RangeResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void Range(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::etcdserverpb::RangeResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::etcdserverpb::RangeResponse>* AsyncRangeRaw(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::etcdserverpb::RangeResponse>* PrepareAsyncRangeRaw(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Range(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::etcdserverpb::RangeResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::etcdserverpb::RangeResponse>> AsyncRange(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::etcdserverpb::RangeResponse>>(AsyncRangeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::etcdserverpb::RangeResponse>> PrepareAsyncRange(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::etcdserverpb::RangeResponse>>(PrepareAsyncRangeRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Range(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest* request, ::etcdserverpb::RangeResponse* response, std::function<void(::grpc::Status)>) override;
      void Range(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::etcdserverpb::RangeResponse* response, std::function<void(::grpc::Status)>) override;
      void Range(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest* request, ::etcdserverpb::RangeResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void Range(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::etcdserverpb::RangeResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::etcdserverpb::RangeResponse>* AsyncRangeRaw(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::etcdserverpb::RangeResponse>* PrepareAsyncRangeRaw(::grpc::ClientContext* context, const ::etcdserverpb::RangeRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Range_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Range gets the keys in the range from the key-value store.
    virtual ::grpc::Status Range(::grpc::ServerContext* context, const ::etcdserverpb::RangeRequest* request, ::etcdserverpb::RangeResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Range : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Range() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Range() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRange(::grpc::ServerContext* context, ::etcdserverpb::RangeRequest* request, ::grpc::ServerAsyncResponseWriter< ::etcdserverpb::RangeResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Range<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Range : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Range() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc_impl::internal::CallbackUnaryHandler< ::etcdserverpb::RangeRequest, ::etcdserverpb::RangeResponse>(
          [this](::grpc::ServerContext* context,
                 const ::etcdserverpb::RangeRequest* request,
                 ::etcdserverpb::RangeResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->Range(context, request, response, controller);
                 }));
    }
    void SetMessageAllocatorFor_Range(
        ::grpc::experimental::MessageAllocator< ::etcdserverpb::RangeRequest, ::etcdserverpb::RangeResponse>* allocator) {
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::etcdserverpb::RangeRequest, ::etcdserverpb::RangeResponse>*>(
          ::grpc::Service::experimental().GetHandler(0))
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Range() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_Range<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Range : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Range() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Range() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Range : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Range() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Range() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRange(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Range : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Range() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Range(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_Range() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Range(::grpc::ServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Range : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Range() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::etcdserverpb::RangeRequest, ::etcdserverpb::RangeResponse>(std::bind(&WithStreamedUnaryMethod_Range<BaseClass>::StreamedRange, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Range() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Range(::grpc::ServerContext* /*context*/, const ::etcdserverpb::RangeRequest* /*request*/, ::etcdserverpb::RangeResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedRange(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::etcdserverpb::RangeRequest,::etcdserverpb::RangeResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Range<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Range<Service > StreamedService;
};

}  // namespace etcdserverpb


#endif  // GRPC_etcd_2eproto__INCLUDED