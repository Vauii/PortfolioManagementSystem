#include <string>
#include <memory>
#include "../../storage/include/IStorageManageger.h"
namespace api_grpc
{

//! Public function for start gRPC-server
void runServer(const std::string& address, std::shared_ptr<storage::IStorageManager> pStoreManager);

//! Public function for stop gRPC-server
void stopServer();

} // namespace api_grpc