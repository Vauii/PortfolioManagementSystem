# Указываем пути к заголовочным файлам
include_directories(include)

# Указываем исходные файлы
set(STORAGE_SOURCES
    src/Storage.cpp
)

# Создаем библиотеку для Storage
add_library(storage ${STORAGE_SOURCES})
