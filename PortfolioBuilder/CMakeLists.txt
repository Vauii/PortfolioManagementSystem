cmake_minimum_required(VERSION 3.16)
project(PortfolioBuilder)

# Используем C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем поддержку тестов
enable_testing()

# Пути к исходным файлам
add_subdirectory(lib/api)
add_subdirectory(lib/stockBuilder)
add_subdirectory(lib/storage)
add_subdirectory(tests)

# Основное приложение
add_executable(PortfolioBuilder app/main.cpp)

# Подключение библиотек
target_link_libraries(PortfolioBuilder PRIVATE api stockBuilder storage)
