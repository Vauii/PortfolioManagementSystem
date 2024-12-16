#include "portfolio.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include "../include/serverGRPC.h"
#include "../include/grpcAPI.h"
using api_grpc::PortfolioServerGRPC;

using grpc::Server;
using grpc::ServerBuilder;

PortfolioServerGRPC*             pService = nullptr;
std::unique_ptr<Server> pServer  = nullptr;

void api_grpc::runServer(const std::string&                        address,
                         std::shared_ptr<storage::IStorageManager> pStoreManager) {
    pService = new PortfolioServerGRPC(pStoreManager);

    ServerBuilder serverBuilder;

    serverBuilder.AddListeningPort(address, grpc::InsecureServerCredentials());

    serverBuilder.RegisterService(pService);
    pServer = serverBuilder.BuildAndStart();
    std::cout << "Server listening on " << address << std::endl;

    pServer->Wait();
}

void api_grpc::stopServer() {
    pServer->Shutdown();

    delete pService;
    delete(pServer.release());
}