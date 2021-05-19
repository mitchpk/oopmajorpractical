#pragma once
#include <string>

class Fuel {
public:
    enum FuelType {
        AIRCRAFT,
        TRUCK,
        SHIP
    };

    float efficiency;
    std::string name;
    FuelType type;
    int pricePerUnit;
};
