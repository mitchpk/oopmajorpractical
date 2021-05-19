#include "Destination.h"
#include "Vehicle.h"

Destination::Destination(std::string name, unsigned int distance, bool accessibleByAir, bool accessibleByLand, bool accessibleBySea) {
    m_name = name;
    m_distance = distance;
    m_accessibleByAir = accessibleByAir;
    m_accessibleByLand = accessibleByLand;
    m_accessibleBySea = accessibleBySea;
}

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


unsigned int Destination::getDistance() {
    return m_distance;
}

std::string Destination::getName() {
    return m_name;
}
