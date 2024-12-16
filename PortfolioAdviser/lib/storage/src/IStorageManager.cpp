#include "../include/IStorageManageger.h"
#include <iostream>

namespace storage {
    std::pair<bool, std::string> IStorageManager::addCSVPortfolio(const std::string& filename, const int64_t& clientId) {
        if (!conn.is_open()) {
            return {false, "Failed to connect to PostgreSQL"};
        }
        std::ifstream csv_file(filename);
        if (!csv_file.is_open()) {
            return {false, "Failed to open CSV file"};
        }
        std::string line, query;
            while (std::getline(csv_file, line)) {
                std::stringstream ss(line);
                std::string stockSymbol, priceOfPurchase, count;

                std::getline(ss, stockSymbol, ',');
                std::getline(ss, priceOfPurchase, ',');
                std::getline(ss, count, ',');
                pqxx::work txn(conn);
                query = "INSERT INTO portfolios (cliend_id, stock_symbol, priceOfPurchase, count) VALUES (" +
                        std::to_string(clientId) + ", " +
                        txn.quote(stockSymbol) + ", " +
                        priceOfPurchase + ", " +
                        count + ")";
                txn.exec(query);
        }
        txn.commit();
        return {true, "Loaded!"};
    }

    std::vector<Value>* IStorageManager::getPortfolioFullInfo(const PortfolioInfoRequest& request){
        std::vector<Value>* v = new std::vector<Value>();
        pqxx::work txn(conn);
        std::string query = "SELECT (stock_symbol, priceOfPurchase, count) FROM portfolios WHERE client_id = " + std::to_string(request.clientId) + ";"
        pqxx::result result = transaction.exec(query);
        for (const pqxx::row &row : res) {
            std::string stockSymbol = row[0].as<std::string>();
            int64_t priceOfPurchase = row[1].as<int64_t>(); 
            int count = row[1].as<int>();
            v->push_back({request.clientId, stockSymbol, priceOfPurchase, count});
        }
        return v;
    };

    
}


