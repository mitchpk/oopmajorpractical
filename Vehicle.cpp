#include <iostream>
#include <string>
#include <vector>

#include "Vehicle.h"
#include "Company.h"

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
void Vehicle::loadPackage(Package package) {
    m_packages.push_back(package);
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

bool Vehicle::buyFuel(Fuel fuel) {
    // if fuel tank is full or wrong fuel type has been selected return false
    if (fuel.type != getFuelType() || m_remainingFuel == m_fuelCapacity) {
        return false;
    }

    if (m_equippedFuel.name != fuel.name) {
        // Player wants to use a different fuel
        if (m_fuelCapacity * fuel.pricePerUnit <= m_company->getBalance()) {
            // Player has enough balance to purchase fuel
            m_equippedFuel = fuel;
            m_remainingFuel = m_fuelCapacity;
            m_company->subractFunds(m_fuelCapacity * fuel.pricePerUnit);
            return true;
        }
    } else {
        // If enters this loop, Player wants to refill the same fuel
        int amountToRefill = m_fuelCapacity - m_remainingFuel;
        if (amountToRefill * fuel.pricePerUnit <= m_company->getBalance()) {
            // Player can purchase
            m_remainingFuel = m_fuelCapacity;
            m_company->subractFunds(amountToRefill * fuel.pricePerUnit);
            return true;
        }
    }
    // otherwise false
    return false;
}

