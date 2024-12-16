#pragma once

#include <vector>
#include <string>

// Структура для представления данных об акции
struct StockData {
    std::string ticker;  // Название акции
    double price;        // Цена акции
    double risk;         // Риск акции
    double returnRate;   // Доходность акции
};

// Класс для формирования оптимального портфеля
class StockBuilder {
public:
    StockBuilder();

    // Формирование портфеля
    std::vector<StockData> buildOptimalPortfolio(const std::vector<StockData>& marketData, int portfolioSize);

private:
    // Метод для сортировки акций по доходности и риску
    static bool compareStocks(const StockData& a, const StockData& b);
};
