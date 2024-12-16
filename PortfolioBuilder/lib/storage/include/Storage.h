#pragma once

#include <vector>
#include <string>
#include "StockBuilder.h"

// Класс для получения данных с биржи
class Storage {
public:
    // Конструктор с указанием источника данных
    explicit Storage(const std::string& source);

    // Получение рыночных данных
    std::vector<StockData> fetchMarketData() const;

private:
    std::string source_; // Путь к источнику данных (файл или API)
};
