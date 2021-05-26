#include "Ship.h"
#include "Company.h"

// constructor
Ship::Ship(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel, Company *company)
    : Vehicle(name, speed, fuelCapacity, fuelBurnRate, price, fuel, company) {}

// destructor
Ship::~Ship() {}

// assigns destination information to ship
void Ship::travel() {
    Destination destination = m_packages[0].getDestination();
    int distanceToTravel = destination.getDistance();
}

// purchases fuel and returns true if successful
bool Ship::buyFuel(Fuel fuel) {
    // if fuel tank is full or wrong fuel type has been selected return false
    if (fuel.type != Fuel::SHIP || m_remainingFuel == m_fuelCapacity) {
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
        // Player wants to refill the same fuel
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

// returns "Ship"
Vehicle::VehicleType Ship::getType() {
    return Vehicle::SHIP;
}
