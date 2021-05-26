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
    
    // constructor for easy initialisation
    Fuel(float efficiency, std::string name, FuelType type, int pricePerUnit) : efficiency(efficiency), name(name), type(type), pricePerUnit(pricePerUnit) {}

    float efficiency;
    std::string name;
    FuelType type;
    int pricePerUnit;
};
