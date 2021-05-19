#include "Package.h"

Package::Package(std::string description, Destination destination, int weight)
    : m_destination(destination) {
    m_description = description;
    m_weight = weight;
}

int Package::getWeight() { return m_weight; }

std::string Package::getDescription() { return m_description; }

Destination Package::getDestination() { return m_destination; }
