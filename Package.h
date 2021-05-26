#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Destination.h"

// represents the packages to be delivered
class Package {
public:
    // constructor
    Package(std::string description, int weight);

    // returns weight of package
    int getWeight();

    // returns description of package
    std::string getDescription();

    // returns destination of package
    Destination getDestination();

    // sets the destination as we are typically picking packages from a list
    void setDestination(Destination destination);

private:
    int m_weight;
    std::string m_description;
    Destination m_destination;
};