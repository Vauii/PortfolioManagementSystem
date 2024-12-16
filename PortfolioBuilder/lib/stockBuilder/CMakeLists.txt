# Указываем пути к заголовочным файлам
include_directories(include)

# Указываем исходные файлы
set(STOCK_BUILDER_SOURCES
    src/stockBuilder.cpp
)

# Создаем библиотеку для StockBuilder
add_library(stockBuilder ${STOCK_BUILDER_SOURCES})
