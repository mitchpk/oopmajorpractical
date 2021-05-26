#include "Package.h"

// constructor
Package::Package(std::string description, int weight) : m_destination(Destination("Dummy", 0, false, false, false)) {
    m_description = description;
    m_weight = weight;
}

// returns package weight
int Package::getWeight() { return m_weight; }

// returns packages description
std::string Package::getDescription() { return m_description; }

// returns packages destination
Destination Package::getDestination() { return m_destination; }

void Package::setDestination(Destination destination) {
    m_destination = destination;
}
