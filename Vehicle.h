#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Package.h"
#include "Fuel.h"

class Vehicle
{
public:
    Vehicle(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel);
    virtual ~Vehicle() {};

    int getSpeed();
    float getFuelBurnRate();
    std::vector<Package> getPackages();
    bool loadPackage(Package package);
    std::string getName();
    int getFuelCapacity();
    int getPrice();

    virtual void travel() = 0;
    virtual bool buyFuel(Fuel fuel, int *companyBalance) = 0;
    virtual std::string getType() = 0;

protected:
    int m_speed;
    float m_fuelBurnRate;
    std::vector<Package> m_packages;
    std::string m_name;
    int m_fuelCapacity;
    int m_remainingFuel;
    int m_price;
    Fuel m_equippedFuel;
};
