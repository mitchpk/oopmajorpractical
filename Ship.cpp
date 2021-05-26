#include "Ship.h"
#include "Company.h"

// constructor
Ship::Ship(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel)
    : Vehicle(name, speed, fuelCapacity, fuelBurnRate, price, fuel) {}

// destructor
Ship::~Ship() {}

// assigns destination information to ship
void Ship::travel() {
    Destination destination = m_packages[0].getDestination();
    int distanceToTravel = destination.getDistance();

    srand(time(NULL));
    int priceReward = m_packages.size() * (1000 + rand() % 1000);

    m_remainingFuel -= (((float)distanceToTravel / 1000) * m_fuelBurnRate) / m_equippedFuel.efficiency;
    if (m_remainingFuel < 0) {
        std::cout << "Your ship ran out of fuel! Please buy some more from the options menu. \n";
        m_remainingFuel = 0;
        return;
    }

    m_packages.clear();

    m_company->addFunds(priceReward);
}

// returns "Ship"
Vehicle::VehicleType Ship::getType() {
    return Vehicle::SHIP;
}

Fuel::FuelType Ship::getFuelType() {
    return Fuel::SHIP;
}
