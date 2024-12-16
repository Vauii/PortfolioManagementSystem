#pragma once

#include <grpcpp/grpcpp.h>
#include "PortfolioBuilder.grpc.pb.h"
#include "Storage.h"
#include "StockBuilder.h"

// Реализация gRPC-сервиса
class PortfolioBuilderServiceImpl final : public PortfolioBuilder::Service {
public:
    PortfolioBuilderServiceImpl();

    // RPC для формирования портфеля
    grpc::Status BuildPortfolio(grpc::ServerContext* context,
                                const BuildPortfolioRequest* request,
                                BuildPortfolioResponse* response) override;

    // RPC для отправки портфеля в PortfolioAdviser
    grpc::Status SendPortfolio(grpc::ServerContext* context,
                               const SendPortfolioRequest* request,
                               SendPortfolioResponse* response) override;

private:
    Storage storage_;       // Модуль для получения и хранения данных с биржи
    StockBuilder builder_;  // Модуль для формирования портфеля
};

// Запуск gRPC-сервера
void RunGrpcServer();
