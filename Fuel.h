#pragma once
#include <string>

// represents different kinds of fuel for vehicles, with different efficiencies and prices
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
