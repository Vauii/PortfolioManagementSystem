#include "grpcApi.h"
#include <iostream>

int main(int argc, char** argv) {
    try {
        std::cout << "Starting Portfolio Builder gRPC Server..." << std::endl;
        RunGrpcServer();
    } catch (const std::exception& ex) {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "An unknown error occurred!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
