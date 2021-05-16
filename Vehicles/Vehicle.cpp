#include <iostream>
#include <string>
#include <vector>

#include "Package.h"
#include "Vehicle.h"


Vehicle::Vehicle(Vehicle::VehicleType variant, int maxSpeed, float fuelBurnRate)
{
    Vehicle::topSpeed = maxSpeed;
    Vehicle::burnRate = fuelBurnRate;
    Vehicle::type = variant;
}


int Vehicle::getTopSpeed()
{
    return Vehicle::topSpeed;
}

float Vehicle::getFuelBurnRate()
{
    return Vehicle::burnRate;
}

std::vector<Package> Vehicle::getPackages()
{
    return currentPackages;
}

