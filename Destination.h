#pragma once
#include <string>

class Vehicle;

// represents the destinations for packages to be delivered to
class Destination {
public:
    // constructor
    Destination(std::string name, unsigned int distance, bool accessibleByAir, bool accessibleByLand, bool accessibleBySea);

    // returns whether or not the parameter vehicle can reach this destination
    bool vehicleCanReach(Vehicle *vehicle);

    // returns the destinations distance
    unsigned int getDistance();

    // returns destination name
    std::string getName();

    // compare different destinations to see if they are the same
    bool equals(Destination other);

private:
    unsigned int m_distance;
    std::string m_name;
    bool m_accessibleByAir;
    bool m_accessibleByLand;
    bool m_accessibleBySea;
};
