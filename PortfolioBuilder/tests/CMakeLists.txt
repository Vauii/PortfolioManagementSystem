# Подключаем GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Подключаем тестируемые модули
include_directories(${CMAKE_SOURCE_DIR}/lib/api/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/stockBuilder/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/storage/include)

# Указываем файлы тестов
set(TEST_SOURCES
    GrpcApiTests.cpp
    StockBuilderTests.cpp
    StorageTests.cpp
)

# Создаем тестовый исполняемый файл
add_executable(tests ${TEST_SOURCES})

# Линкуем тесты с GoogleTest и модулями проекта
target_link_libraries(tests PRIVATE GTest::GTest GTest::Main api stockBuilder storage)

# Добавляем команду для запуска тестов
add_test(NAME AllTests COMMAND tests)
