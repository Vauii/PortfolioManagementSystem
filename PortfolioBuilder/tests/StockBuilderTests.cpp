#include "StockBuilder.h"
#include <gtest/gtest.h>

// Тест: Проверка правильности сортировки акций
TEST(StockBuilderTest, BuildOptimalPortfolioSorting) {
    StockBuilder builder;

    std::vector<StockData> marketData = {
        {"AAPL", 150.0, 0.2, 0.05},
        {"MSFT", 300.0, 0.15, 0.07},
        {"GOOG", 2800.0, 0.1, 0.1},
        {"TSLA", 700.0, 0.3, 0.06}
    };

    auto portfolio = builder.buildOptimalPortfolio(marketData, 3);

    ASSERT_EQ(portfolio.size(), 3);
    EXPECT_EQ(portfolio[0].ticker, "GOOG"); // Самая высокая доходность
    EXPECT_EQ(portfolio[1].ticker, "MSFT"); // Вторая по доходности
    EXPECT_EQ(portfolio[2].ticker, "TSLA"); // Третья по доходности
}

// Тест: Проверка ограничений размера портфеля
TEST(StockBuilderTest, BuildOptimalPortfolioSize) {
    StockBuilder builder;

    std::vector<StockData> marketData = {
        {"AAPL", 150.0, 0.2, 0.05},
        {"MSFT", 300.0, 0.15, 0.07}
    };

    auto portfolio = builder.buildOptimalPortfolio(marketData, 5);
    ASSERT_EQ(portfolio.size(), 2); // Данных меньше, чем запрошено
}
