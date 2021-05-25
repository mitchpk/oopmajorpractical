#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Destination.h"

// represents the packages to be delivered
class Package {
public:
    // constructor
    Package(std::string description, Destination destination, int weight);

    // returns weight of package
    int getWeight();

    // returns description of package
    std::string getDescription();

    // returns destination of package
    Destination getDestination();

private:
    int m_weight;
    std::string m_description;
    Destination m_destination;
};
