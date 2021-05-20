#include <iostream>
#include <string>
#include <vector>

#include "Vehicle.h"


Vehicle::Vehicle(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel) {
    m_speed = speed;
    m_fuelBurnRate = fuelBurnRate;
    m_name = name;
    m_fuelCapacity = fuelCapacity;
    m_price = price;
    m_remainingFuel = fuelCapacity;
    m_equippedFuel = fuel;
}


int Vehicle::getSpeed() {
    return m_speed;
}

float Vehicle::getFuelBurnRate() {
    return m_fuelBurnRate;
}

std::vector<Package> Vehicle::getPackages() {
    return m_packages;
}

bool Vehicle::loadPackage(Package package) {
    if (m_packages.empty()) {
        m_packages.push_back(package);
        return true;
    }

    return false;
}

std::string Vehicle::getName() {
    return m_name;
}

int Vehicle::getFuelCapacity() {
    return m_fuelCapacity;
}

int Vehicle::getPrice() {
    return m_price;
}
