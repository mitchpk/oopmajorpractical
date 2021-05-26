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

    srand(time(NULL));
    int priceReward = m_packages.size() * (1000 + rand() % 1000);

    m_remainingFuel -= (((float)distanceToTravel / 1000) * m_fuelBurnRate) / m_equippedFuel.efficiency;
    if (m_remainingFuel < 0) {
        std::cout << "Your aircraft ran out of fuel!\n";
        m_remainingFuel = 0;
        return;
    }

    m_packages.clear();
    m_company->addFunds(priceReward);
}

// purchases fuel and returns true if successful
// returns "Aircraft"
Vehicle::VehicleType Aircraft::getType() {
    return Vehicle::AIRCRAFT;
}

Fuel::FuelType Aircraft::getFuelType() {
    return Fuel::AIRCRAFT;
}
