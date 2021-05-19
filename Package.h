#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Destination.h"

class Package {
public:
    Package(std::string description, Destination destination, int weight);

    int getWeight();
    std::string getDescription();
    Destination getDestination();

private:
    int m_weight;
    std::string m_description;
    Destination m_destination;
};
