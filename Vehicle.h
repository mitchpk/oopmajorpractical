#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Package.h"

class Vehicle
{
public:
    Vehicle(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price);
    virtual ~Vehicle() = 0;

    int getSpeed();
    float getFuelBurnRate();
    std::vector<Package> getPackages();
    bool loadPackage(Package package);
    std::string getName();
    int getFuelCapacity();
    int getPrice();

    virtual void travel() = 0;
    virtual bool buyFuel(int amount) = 0;
    virtual std::string getType() = 0;

private:
    int m_speed;
    float m_fuelBurnRate;
    std::vector<Package> m_packages;
    std::string m_name;
    int m_fuelCapacity;
    int m_price;
};
