#include "StockBuilder.h"
#include <algorithm>

// Конструктор
StockBuilder::StockBuilder() {}

// Метод для формирования оптимального портфеля
std::vector<StockData> StockBuilder::buildOptimalPortfolio(const std::vector<StockData>& marketData, int portfolioSize) {
    // Копируем данные для сортировки
    std::vector<StockData> sortedData = marketData;

    // Сортируем акции по убыванию доходности, затем по возрастанию риска
    std::sort(sortedData.begin(), sortedData.end(), compareStocks);

    // Ограничиваем размер портфеля
    if (portfolioSize > static_cast<int>(sortedData.size())) {
        portfolioSize = sortedData.size();
    }

    // Возвращаем top-N акций
    return std::vector<StockData>(sortedData.begin(), sortedData.begin() + portfolioSize);
}

// Статический метод для сравнения акций
bool StockBuilder::compareStocks(const StockData& a, const StockData& b) {
    if (a.returnRate == b.returnRate) {
        return a.risk < b.risk; // Меньший риск предпочтительнее
    }
    return a.returnRate > b.returnRate; // Большая доходность предпочтительнее
}
