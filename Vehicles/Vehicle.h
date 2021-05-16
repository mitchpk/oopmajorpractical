#include <iostream>
#include <string>
#include <vector>

#include "Package.h"

class Vehicle
{
    public:
        enum VehicleType
        {
            AIRCRAFT,
            TRUCK,
            SHIP
        };
        Vehicle(Vehicle::VehicleType variant, int topSpeed, float fuelBurnRate);

        int getTopSpeed();
        float getFuelBurnRate();
        std::vector<Package> getPackages();


    private:

        int topSpeed;
        float burnRate;
        std::vector<Package> currentPackages;
        VehicleType type;
};