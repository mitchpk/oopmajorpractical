#pragma once
#include "Vehicle.h"
#include "Fuel.h"

class Truck : public Vehicle {
public:
    Truck(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel);
    void travel() override;
    bool buyFuel(Fuel fuel) override;
    std::string getType() override;
};
