#include "grpcApi.h"
#include "PortfolioBuilder.grpc.pb.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Мок для gRPC контекста
class MockGrpcContext : public grpc::ServerContext {};

// Тест: Проверка вызова BuildPortfolio
TEST(GrpcApiTest, BuildPortfolioSuccess) {
    PortfolioBuilderServiceImpl service;

    MockGrpcContext context;
    BuildPortfolioRequest request;
    BuildPortfolioResponse response;

    auto status = service.BuildPortfolio(&context, &request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(response.stocks_size(), 5); // Количество акций в заглушке Storage
    EXPECT_EQ(response.status(), "Portfolio successfully built.");
}

// Тест: Проверка вызова SendPortfolio
TEST(GrpcApiTest, SendPortfolioSuccess) {
    PortfolioBuilderServiceImpl service;

    MockGrpcContext context;
    SendPortfolioRequest request;
    SendPortfolioResponse response;

    auto status = service.SendPortfolio(&context, &request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(response.status(), "Portfolio sent to PortfolioAdviser.");
}
