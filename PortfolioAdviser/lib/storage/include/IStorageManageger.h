#pragma once
#include <pqxx/pqxx>
#include "DTOs.h"
#include <vector> 
#include <string>
#include <fstream>
#include <sstream>

namespace storage{

    class IStorageManager {
    public:
        IStorageManager(const std::string& connectionString) : conn(connectionString) {};

        std::pair<bool, std::string> addCSVPortfolio(const std::string& filename, const int64_t& clientId);

        std::vector<Value>* getPortfolioFullInfo(const PortfolioInfoRequest& request);

        bool addPortfolio(const std::vector<Value>& values);

    private:
        pqxx::connection conn;
        void insertData(const std::vector<std::string>& data);
    };
    
}
