// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: string_processor.proto

#include "string_processor.pb.h"
#include "string_processor.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace stringprocessor {

static const char* StringService_method_names[] = {
  "/stringprocessor.StringService/Process",
};

std::unique_ptr< StringService::Stub> StringService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< StringService::Stub> stub(new StringService::Stub(channel));
  return stub;
}

StringService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Process_(StringService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status StringService::Stub::Process(::grpc::ClientContext* context, const ::stringprocessor::StringRequest& request, ::stringprocessor::StringResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Process_, context, request, response);
}

void StringService::Stub::experimental_async::Process(::grpc::ClientContext* context, const ::stringprocessor::StringRequest* request, ::stringprocessor::StringResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Process_, context, request, response, std::move(f));
}

void StringService::Stub::experimental_async::Process(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::stringprocessor::StringResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Process_, context, request, response, std::move(f));
}

void StringService::Stub::experimental_async::Process(::grpc::ClientContext* context, const ::stringprocessor::StringRequest* request, ::stringprocessor::StringResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Process_, context, request, response, reactor);
}

void StringService::Stub::experimental_async::Process(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::stringprocessor::StringResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Process_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::stringprocessor::StringResponse>* StringService::Stub::AsyncProcessRaw(::grpc::ClientContext* context, const ::stringprocessor::StringRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::stringprocessor::StringResponse>::Create(channel_.get(), cq, rpcmethod_Process_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::stringprocessor::StringResponse>* StringService::Stub::PrepareAsyncProcessRaw(::grpc::ClientContext* context, const ::stringprocessor::StringRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::stringprocessor::StringResponse>::Create(channel_.get(), cq, rpcmethod_Process_, context, request, false);
}

StringService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StringService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StringService::Service, ::stringprocessor::StringRequest, ::stringprocessor::StringResponse>(
          [](StringService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::stringprocessor::StringRequest* req,
             ::stringprocessor::StringResponse* resp) {
               return service->Process(ctx, req, resp);
             }, this)));
}

StringService::Service::~Service() {
}

::grpc::Status StringService::Service::Process(::grpc::ServerContext* context, const ::stringprocessor::StringRequest* request, ::stringprocessor::StringResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace stringprocessor

