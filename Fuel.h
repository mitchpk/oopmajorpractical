#pragma once
#include <string>

// represents the fuel for the vehicles
class Fuel {
public:
    // enum used to allocate numerical values to fuel types
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
