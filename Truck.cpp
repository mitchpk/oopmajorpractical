#include "Truck.h"
#include "Company.h"

// constructor
Truck::Truck(std::string name, int speed, int fuelCapacity, float fuelBurnRate, int price, Fuel fuel)
    : Vehicle(name, speed, fuelCapacity, fuelBurnRate, price, fuel) {}

// destructor
Truck::~Truck() {}

// assigns destination information to truck
void Truck::travel() {
    Destination destination = m_packages[0].getDestination();
    int distanceToTravel = destination.getDistance();

    srand(time(NULL));
    int priceReward = m_packages.size() * (1000 + rand() % 1000);

    m_remainingFuel -= (((float)distanceToTravel / 1000) * m_fuelBurnRate) / m_equippedFuel.efficiency;
    if (m_remainingFuel < 0) {
        std::cout << "Your truck ran out of fuel! Please buy some more from the options menu!\n";
        m_remainingFuel = 0;
        return;
    }

    m_packages.clear();

    m_company->addFunds(priceReward);
}

// returns "Truck"
Vehicle::VehicleType Truck::getType() {
    return Vehicle::TRUCK;
}

Fuel::FuelType Truck::getFuelType() {
    return Fuel::TRUCK;
}
