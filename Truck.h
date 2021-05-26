#pragma once
#include "Vehicle.h"
#include "Fuel.h"

// represents a type of vehicle, the truck, which inherits functionality from the Vehicle class
class Truck : public Vehicle {
public:
    // constructor
    Truck(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel);
    ~Truck();

    // attempt to make a trip based on currently loaded packages
    void travel() override;

    // purchases fuel and returns true if successful
    bool buyFuel(Fuel fuel) override;

    // returns "Truck"
    VehicleType getType() override;
};
