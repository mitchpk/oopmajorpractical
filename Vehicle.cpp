#include <iostream>
#include <string>
#include <vector>

#include "Vehicle.h"


Vehicle::Vehicle(int speed, float fuelBurnRate) {
    m_speed = speed;
    m_burnRate = fuelBurnRate;
}


int Vehicle::getSpeed() {
    return m_speed;
}

float Vehicle::getFuelBurnRate() {
    return m_burnRate;
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
