#include "Truck.h"

// constructor
Truck::Truck(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel)
    : Vehicle(name, speed, fuelCapacity, fuelBurnRate, price, fuel) {}

// destructor
Truck::~Truck() {}

// assigns destination information to truck
void Truck::travel() {
    Destination destination = m_packages[0].getDestination();
    int distanceToTravel = destination.getDistance();
}

// purchases fuel and returns true if successful
bool Truck::buyFuel(Fuel fuel) {
    // if fuel tank is full or wrong fuel type has been selected return false
    if (fuel.type != Fuel::TRUCK || m_remainingFuel == m_fuelCapacity) {
        return false;
    }

    if (m_equippedFuel.name != fuel.name) {
        // Player wants to use a different fuel
        if (m_fuelCapacity * fuel.pricePerUnit < *companyBalance) {
            // Player has enough balance to purchase fuel
            m_equippedFuel = fuel;
            m_remainingFuel = m_fuelCapacity;
            *companyBalance -= m_fuelCapacity * fuel.pricePerUnit;
            return true;
        }
    } else {
        // Player wants to refill the same fuel
        int amountToRefill = m_fuelCapacity - m_remainingFuel;
        if (amountToRefill * fuel.pricePerUnit < *companyBalance) {
            // Player can purchase
            m_remainingFuel = m_fuelCapacity;
            *companyBalance -= amountToRefill * fuel.pricePerUnit;
            return true;
        }
    }
    // otherwise false
    return false;
}

// returns "Truck"
std::string Truck::getType() {
    return "Truck";
}
