#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Package.h"

class Vehicle
{
public:
    Vehicle(int speed, float fuelBurnRate);

    int getSpeed();
    float getFuelBurnRate();
    std::vector<Package> getPackages();
    bool loadPackage(Package package);

    virtual void travel() = 0;
    virtual bool buyFuel(int amount) = 0;
    virtual std::string getType() = 0;

private:
    int m_speed;
    float m_burnRate;
    std::vector<Package> m_packages;
};
