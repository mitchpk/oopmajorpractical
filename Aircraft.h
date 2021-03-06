#pragma once
#include "Vehicle.h"
#include "Fuel.h"

// represents a type of vehicle, the truck, which inherits functionality from the Vehicle class
class Aircraft : public Vehicle {
public:
    // constructor
    Aircraft(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel);
    ~Aircraft();

    // attempt to make a trip based on currently loaded packages
    void travel() override;

    // returns "Aircraft"
    VehicleType getType() override;
    Fuel::FuelType getFuelType() override;
};
