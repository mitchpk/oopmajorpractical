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

    // Constructor which allows us to initialize the properties
    //of the fuel, allowing us to create as many different variants
    // as we need for the game
    Fuel(float efficiency, std::string name, FuelType type, int pricePerUnit) : efficiency(efficiency), name(name), type(type), pricePerUnit(pricePerUnit) {}

    float efficiency;
    std::string name;
    FuelType type;
    int pricePerUnit;
};
