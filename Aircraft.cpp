#include "Aircraft.h"
#include "Company.h"

// constructor
Aircraft::Aircraft(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel)
    : Vehicle(name, speed, fuelCapacity, fuelBurnRate, price, fuel) {}

// destructor
Aircraft::~Aircraft() {}

// assigns destination information to aircraft
void Aircraft::travel() {
    Destination destination = m_packages[0].getDestination();
    int distanceToTravel = destination.getDistance();
}

// purchases fuel and returns true if successful
bool Aircraft::buyFuel(Fuel fuel) {
    // if fuel tank is full or wrong fuel type has been selected return false
    if (fuel.type != Fuel::AIRCRAFT || m_remainingFuel == m_fuelCapacity) {
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

// returns "Aircraft"
Vehicle::VehicleType Aircraft::getType() {
    return Vehicle::AIRCRAFT;
}
