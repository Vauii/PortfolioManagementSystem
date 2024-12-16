#include "Storage.h"
#include <iostream>
#include <stdexcept>

// Конструктор
Storage::Storage(const std::string& source) : source_(source) {}

// Получение рыночных данных
std::vector<StockData> Storage::fetchMarketData() const {
    // Заглушка: эмуляция загрузки данных
    // В реальной реализации можно добавить чтение данных из файла или запрос к API
    std::vector<StockData> marketData = {
        {"AAPL", 150.0, 0.2, 0.05},
        {"MSFT", 300.0, 0.15, 0.07},
        {"GOOG", 2800.0, 0.1, 0.1},
        {"AMZN", 3500.0, 0.25, 0.04},
        {"TSLA", 700.0, 0.3, 0.06}
    };

    if (marketData.empty()) {
        throw std::runtime_error("Failed to fetch market data from source: " + source_);
    }

    return marketData;
}
