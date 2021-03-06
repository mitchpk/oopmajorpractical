#pragma once
#include "Fuel.h"
#include "Vehicle.h"

// represents a type of vehicle, the truck, which inherits functionality from
// the Vehicle class
class Ship : public Vehicle {
public:
    // constructor
    Ship(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel);
    ~Ship();

    // attempt to make a trip based on currently loaded packages
    void travel() override;

    // returns "Ship"
    VehicleType getType() override;
    Fuel::FuelType getFuelType() override;
};
