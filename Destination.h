#pragma once
#include <string>

class Vehicle;

class Destination {
public:
    Destination(std::string name, unsigned int distance, bool accessibleByAir, bool accessibleByLand, bool accessibleBySea);

    bool vehicleCanReach(Vehicle *vehicle);
    unsigned int getDistance();
    std::string getName();

private:
    unsigned int m_distance;
    std::string m_name;
    bool m_accessibleByAir;
    bool m_accessibleByLand;
    bool m_accessibleBySea;
};
