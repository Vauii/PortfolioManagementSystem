# gRPC и Protocol Buffers
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

# Указываем пути к заголовочным файлам
include_directories(include)

# Указываем исходные файлы
set(API_SOURCES
    src/grpcApi.cpp
    src/PortfolioBuilder.grpc.pb.cc
    src/PortfolioBuilder.pb.cc
)

# Создаем библиотеку для API
add_library(api ${API_SOURCES})

# Линкуем библиотеки gRPC и Protocol Buffers
target_link_libraries(api PUBLIC gRPC::grpc++ protobuf::libprotobuf)
