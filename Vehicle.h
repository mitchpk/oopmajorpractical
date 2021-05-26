#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Package.h"
#include "Fuel.h"

class Company;

// represents a base vehicle class which will be inherited
class Vehicle
{
public:
    enum VehicleType {
        AIRCRAFT,
        TRUCK,
        SHIP
    };

    // constructor
    Vehicle(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel);

    // destructor
    virtual ~Vehicle() {};

    // returns vehicle speed
    int getSpeed();

    // returns vehicles fuel burn rate
    float getFuelBurnRate();

    // returns vector of all packages on vehicle
    std::vector<Package> getPackages();

    // add cargo to vehicle 
    void loadPackage(Package package);

    // returns name of vehicle
    std::string getName();

    // returns vehicles fuel capacity
    int getFuelCapacity();

    // returns current fuel stored in vehicle
    int getRemainingFuel();

    // returns price of vehicle
    int getPrice();
    
    bool buyFuel(Fuel fuel);

    // set the owner
    void setCompany(Company *company);

    // pure virtual functions to be defined in child classes
    virtual void travel() = 0;
    virtual Fuel::FuelType getFuelType() = 0;
    virtual VehicleType getType() = 0;

protected:
    int m_speed;
    float m_fuelBurnRate;
    std::vector<Package> m_packages;
    std::string m_name;
    int m_fuelCapacity;
    int m_remainingFuel;
    int m_price;
    Fuel m_equippedFuel;
    Company *m_company;
};;
