#include <iostream>
#include <string>
#include <vector>

#include "Vehicle.h"

// constructor
Vehicle::Vehicle(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel) : m_equippedFuel(fuel) {
    m_speed = speed;
    m_fuelBurnRate = fuelBurnRate;
    m_name = name;
    m_fuelCapacity = fuelCapacity;
    m_price = price;
    m_remainingFuel = fuelCapacity;
}

// returns vehicle speed
int Vehicle::getSpeed() {
    return m_speed;
}

// returns vehicles fuel burnrate
float Vehicle::getFuelBurnRate() {
    return m_fuelBurnRate;
}

// returns vector of vehicles packages
std::vector<Package> Vehicle::getPackages() {
    return m_packages;
}

// attempts to load package and if successful returns true, otherwise false
bool Vehicle::loadPackage(Package package) {
    if (m_packages.empty()) {
        m_packages.push_back(package);
        return true;
    }

    return false;
}

// returns name of vehicle
std::string Vehicle::getName() {
    return m_name;
}

// returns vehicles fuel capacity
int Vehicle::getFuelCapacity() {
    return m_fuelCapacity;
}

// returns price of vehicle
int Vehicle::getPrice() {
    return m_price;
}

void Vehicle::setCompany(Company *company) {
    m_company = company;
}

int Vehicle::getRemainingFuel() {
    return m_remainingFuel;
}
