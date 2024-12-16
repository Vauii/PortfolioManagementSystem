#pragma once

#include "../src/portfolio.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include "../../storage/include/IStorageManageger.h"

#include <memory>


namespace api_grpc
{

//! gRPC-server implementation
class PortfolioServerGRPC final : public backendservice::PortfolioService::Service {

private:
    std::shared_ptr<storage::IStorageManager> pStoreManager;
public:
    //! Ctor by default
    PortfolioServerGRPC() = delete;

    //! Constructor
    PortfolioServerGRPC(std::shared_ptr<storage::IStorageManager> pStoreManager);

    //! Destructor
    ~PortfolioServerGRPC();

    grpc::Status postCsv(
        grpc::ServerContext* context,
        const backendservice::PortfolioCSVRequest* request,
        backendservice::PortfolioCSVResponse* response
    ) override;

    grpc::Status putPortfolio(
        grpc::ServerContext* context,
        const backendservice::PortfolioCSVRequest* request,
        backendservice::PortfolioCSVResponse* response
    )override;

    grpc::Status getPortfolioInfo(
        grpc::ServerContext* context,
        const backendservice::PortfolioInfoRequest* request,
        backendservice::PortfolioInfoResponse* response
    )override;

    grpc::Status addRecomendedValues(
        grpc::ServerContext* context,
        const backendservice::RecomendedValuesRequest* request,
        backendservice::RecomendedValuesResponse* response
    )override;

};
}