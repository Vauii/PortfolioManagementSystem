#include "../src/briefcaseserver.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include "../../storage/include/IStorageManageger.h"

#include <memory>


namespace api_grpc
{

//! gRPC-server implementation
class BriefcaseServerGRPC final : public backendservice::BriefcaseService::Service {
public:
    //! Ctor by default
    BriefcaseServerGRPC() = delete;

    //! Constructor
    BriefcaseServerGRPC(std::shared_ptr<storage::IStorageManager> pStoreManager);

    //! Destructor
    ~BriefcaseServerGRPC();

    grpc::Status postCsv(
        grpc::ServerContext* context,
        const backendservice::BriefcaseCSVRequest* request,
        backendservice::BriefcaseCSVResponse* response
    ) override;

    grpc::Status putBreafecase(
        grpc::ServerContext* context,
        const backendservice::BriefcaseCSVRequest* request,
        backendservice::BriefcaseCSVResponse* response
    )override;

    grpc::Status getBreifcaseInfo(
        grpc::ServerContext* context,
        const backendservice::BriefcaseInfoRequest* request,
        backendservice::BriefcaseInfoResponse* response
    )override;

    grpc::Status addRecomendedValues(
        grpc::ServerContext* context,
        const backendservice::RecomendedValuesRequest* request,
        backendservice::RecomendedValuesResponse* response
    )override;
    
};
}