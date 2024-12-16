#include "Storage.h"
#include <gtest/gtest.h>

// Тест: Проверка загрузки рыночных данных
TEST(StorageTest, FetchMarketData) {
    Storage storage("mock_source");

    auto marketData = storage.fetchMarketData();

    ASSERT_FALSE(marketData.empty()); // Данные должны быть загружены
    EXPECT_EQ(marketData.size(), 5);  // Проверяем количество акций
    EXPECT_EQ(marketData[0].ticker, "AAPL"); // Первая акция - AAPL
}
