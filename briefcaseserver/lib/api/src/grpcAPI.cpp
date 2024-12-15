#include "briefcaseserver.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include "../include/serverGRPC.h"
#include "../include/grpcAPI.h"
using api_grpc::BriefcaseServerGRPC;

using grpc::Server;
using grpc::ServerBuilder;

BriefcaseServerGRPC*             pService = nullptr;
std::unique_ptr<Server> pServer  = nullptr;

void api_grpc::runServer(const std::string&                        address,
                         std::shared_ptr<storage::IStorageManager> pStoreManager) {
    // создаем свой сервис
    pService = new BriefcaseServerGRPC(pStoreManager);

    // создаем gRPC-шный server builder
    ServerBuilder serverBuilder;

    // добавляем порт и специфицируем вид подключения (не защищенное)
    serverBuilder.AddListeningPort(address, grpc::InsecureServerCredentials());

    // регистрируем наш собственный сервис и запускаем
    serverBuilder.RegisterService(pService);
    pServer = serverBuilder.BuildAndStart();
    std::cout << "Server listening on " << address << std::endl;

    // этот метод является блокирующим
    pServer->Wait();
}

//! Public function for stop gRPC-server
void api_grpc::stopServer() {
    // этот метод завершит блокоирующий Wait()
    pServer->Shutdown();

    delete pService;
    delete(pServer.release());
}