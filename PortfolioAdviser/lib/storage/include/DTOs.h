#include <cstdint>
#include <string>

#pragma once

namespace storage {

enum EPrediction : int {
  STAY = 0,
  SELL = 1,
  UNPROFITABLE = 2
};

struct Value {
    int64_t clientId;
    std::string stockSymbol;
    std::string priceOfPurchase;
    int count;
};

enum EInfoType {
    FULL = 0, //full info 
    RISED = 2, //only rised 
    FALLEN = 3 //only fallen
};

struct PortfolioInfoRequest {
    int64_t clientId; //client id
    EInfoType infoType;
};




}