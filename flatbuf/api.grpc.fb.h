// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: api
#ifndef GRPC_api__INCLUDED
#define GRPC_api__INCLUDED

#include "api_generated.h"
#include "flatbuffers/grpc.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace Api {

class TransactionRepository GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status find(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, flatbuffers::BufferRef<TransactionResponse>* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<TransactionResponse>>> Asyncfind(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<TransactionResponse>>>(AsyncfindRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<TransactionResponse>>* AsyncfindRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status find(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, flatbuffers::BufferRef<TransactionResponse>* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<TransactionResponse>>> Asyncfind(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<TransactionResponse>>>(AsyncfindRaw(context, request, cq));
    }
  
   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<TransactionResponse>>* AsyncfindRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_find_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
  
  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status find(::grpc::ServerContext* context, const flatbuffers::BufferRef<Query>* request, flatbuffers::BufferRef<TransactionResponse>* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_find : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_find() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_find() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status find(::grpc::ServerContext* context, const flatbuffers::BufferRef<Query>* request, flatbuffers::BufferRef<TransactionResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestfind(::grpc::ServerContext* context, flatbuffers::BufferRef<Query>* request, ::grpc::ServerAsyncResponseWriter< flatbuffers::BufferRef<TransactionResponse>>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef   WithAsyncMethod_find<  Service   >   AsyncService;
  template <class BaseClass>
  class WithGenericMethod_find : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_find() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_find() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status find(::grpc::ServerContext* context, const flatbuffers::BufferRef<Query>* request, flatbuffers::BufferRef<TransactionResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

class AssetRepository GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status find(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, flatbuffers::BufferRef<AssetResponse>* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<AssetResponse>>> Asyncfind(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<AssetResponse>>>(AsyncfindRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<AssetResponse>>* AsyncfindRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status find(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, flatbuffers::BufferRef<AssetResponse>* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<AssetResponse>>> Asyncfind(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<AssetResponse>>>(AsyncfindRaw(context, request, cq));
    }
  
   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<AssetResponse>>* AsyncfindRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Query>& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_find_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
  
  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status find(::grpc::ServerContext* context, const flatbuffers::BufferRef<Query>* request, flatbuffers::BufferRef<AssetResponse>* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_find : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_find() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_find() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status find(::grpc::ServerContext* context, const flatbuffers::BufferRef<Query>* request, flatbuffers::BufferRef<AssetResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestfind(::grpc::ServerContext* context, flatbuffers::BufferRef<Query>* request, ::grpc::ServerAsyncResponseWriter< flatbuffers::BufferRef<AssetResponse>>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef   WithAsyncMethod_find<  Service   >   AsyncService;
  template <class BaseClass>
  class WithGenericMethod_find : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_find() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_find() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status find(::grpc::ServerContext* context, const flatbuffers::BufferRef<Query>* request, flatbuffers::BufferRef<AssetResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

class Sumeragi GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Torii(::grpc::ClientContext* context, const flatbuffers::BufferRef<Request>& request, flatbuffers::BufferRef<StatusResponse>* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<StatusResponse>>> AsyncTorii(::grpc::ClientContext* context, const flatbuffers::BufferRef<Request>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<StatusResponse>>>(AsyncToriiRaw(context, request, cq));
    }
    virtual ::grpc::Status Verify(::grpc::ClientContext* context, const flatbuffers::BufferRef<ConsensusEvent>& request, flatbuffers::BufferRef<StatusResponse>* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<StatusResponse>>> AsyncVerify(::grpc::ClientContext* context, const flatbuffers::BufferRef<ConsensusEvent>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<StatusResponse>>>(AsyncVerifyRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<StatusResponse>>* AsyncToriiRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Request>& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< flatbuffers::BufferRef<StatusResponse>>* AsyncVerifyRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<ConsensusEvent>& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Torii(::grpc::ClientContext* context, const flatbuffers::BufferRef<Request>& request, flatbuffers::BufferRef<StatusResponse>* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<StatusResponse>>> AsyncTorii(::grpc::ClientContext* context, const flatbuffers::BufferRef<Request>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<StatusResponse>>>(AsyncToriiRaw(context, request, cq));
    }
    ::grpc::Status Verify(::grpc::ClientContext* context, const flatbuffers::BufferRef<ConsensusEvent>& request, flatbuffers::BufferRef<StatusResponse>* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<StatusResponse>>> AsyncVerify(::grpc::ClientContext* context, const flatbuffers::BufferRef<ConsensusEvent>& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<StatusResponse>>>(AsyncVerifyRaw(context, request, cq));
    }
  
   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<StatusResponse>>* AsyncToriiRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Request>& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<StatusResponse>>* AsyncVerifyRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<ConsensusEvent>& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_Torii_;
    const ::grpc::RpcMethod rpcmethod_Verify_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
  
  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Torii(::grpc::ServerContext* context, const flatbuffers::BufferRef<Request>* request, flatbuffers::BufferRef<StatusResponse>* response);
    virtual ::grpc::Status Verify(::grpc::ServerContext* context, const flatbuffers::BufferRef<ConsensusEvent>* request, flatbuffers::BufferRef<StatusResponse>* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Torii : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Torii() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Torii() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Torii(::grpc::ServerContext* context, const flatbuffers::BufferRef<Request>* request, flatbuffers::BufferRef<StatusResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestTorii(::grpc::ServerContext* context, flatbuffers::BufferRef<Request>* request, ::grpc::ServerAsyncResponseWriter< flatbuffers::BufferRef<StatusResponse>>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Verify : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Verify() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Verify() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Verify(::grpc::ServerContext* context, const flatbuffers::BufferRef<ConsensusEvent>* request, flatbuffers::BufferRef<StatusResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestVerify(::grpc::ServerContext* context, flatbuffers::BufferRef<ConsensusEvent>* request, ::grpc::ServerAsyncResponseWriter< flatbuffers::BufferRef<StatusResponse>>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef   WithAsyncMethod_Torii<  WithAsyncMethod_Verify<  Service   >   >   AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Torii : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Torii() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Torii() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Torii(::grpc::ServerContext* context, const flatbuffers::BufferRef<Request>* request, flatbuffers::BufferRef<StatusResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Verify : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Verify() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Verify() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Verify(::grpc::ServerContext* context, const flatbuffers::BufferRef<ConsensusEvent>* request, flatbuffers::BufferRef<StatusResponse>* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace Api


#endif  // GRPC_api__INCLUDED