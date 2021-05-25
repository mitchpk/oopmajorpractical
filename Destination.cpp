#include "Destination.h"
#include "Vehicle.h"

// constructor
Destination::Destination(std::string name, unsigned int distance, bool accessibleByAir, bool accessibleByLand, bool accessibleBySea) {
    m_name = name;
    m_distance = distance;
    m_accessibleByAir = accessibleByAir;
    m_accessibleByLand = accessibleByLand;
    m_accessibleBySea = accessibleBySea;
}

// returns whether or not the parameter vehicle can reach the destiation
bool Destination::vehicleCanReach(Vehicle *vehicle) {
    if (vehicle->getType() == "Aircraft") {
        return m_accessibleByAir;
    }

    if (vehicle->getType() == "Truck") {
        return m_accessibleByLand;
    }

    if (vehicle->getType() == "Ship") {
        return m_accessibleBySea;
    }

    return false;
}

// returns destinations distance
unsigned int Destination::getDistance() {
    return m_distance;
}

// returns destinations name
std::string Destination::getName() {
    return m_name;
}
