#include "grpcApi.h"
#include <iostream>

// Конструктор сервиса
PortfolioBuilderServiceImpl::PortfolioBuilderServiceImpl()
    : storage_("mosbirzha_mock.json"), builder_() {}

// Реализация RPC BuildPortfolio
grpc::Status PortfolioBuilderServiceImpl::BuildPortfolio(
    grpc::ServerContext* context,
    const BuildPortfolioRequest* request,
    BuildPortfolioResponse* response) {

    // Получаем данные с биржи
    auto marketData = storage_.fetchMarketData();

    // Формируем оптимальный портфель
    auto portfolio = builder_.buildOptimalPortfolio(marketData, 1000);

    // Добавляем акции в ответ
    for (const auto& stock : portfolio) {
        auto stockInfo = response->add_stocks();
        stockInfo->set_ticker(stock.ticker);
        stockInfo->set_price(stock.price);
        stockInfo->set_quantity(100); // Заглушка: фиксированное количество акций
    }

    response->set_status("Portfolio successfully built.");
    return grpc::Status::OK;
}

// Реализация RPC SendPortfolio
grpc::Status PortfolioBuilderServiceImpl::SendPortfolio(
    grpc::ServerContext* context,
    const SendPortfolioRequest* request,
    SendPortfolioResponse* response) {

    // Заглушка: отправляем портфель в PortfolioAdviser
    response->set_status("Portfolio sent to PortfolioAdviser.");
    return grpc::Status::OK;
}

// Функция запуска gRPC-сервера
void RunGrpcServer() {
    std::string server_address("0.0.0.0:50051");
    PortfolioBuilderServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "gRPC Server listening on " << server_address << std::endl;
    server->Wait();
}
