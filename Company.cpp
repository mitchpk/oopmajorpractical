#include "Company.h"
#include <algorithm>

Company::Company(std::string name) {
    m_name = name;
    m_balance = 0;
}

Company::~Company() {
    for (auto v : m_ownedVehicles) {
        delete v;
    }
}

bool Company::purchaseVehicle(Vehicle *vehicle) { return true; }

bool Company::purchaseFuel(Vehicle *vehicle, Fuel fuel, int quantity) { 
    if (ownsVehicle(vehicle)) return true;
    return false;
}

bool Company::ownsVehicle(Vehicle *vehicle) {
    return std::find(m_ownedVehicles.begin(), m_ownedVehicles.end(), vehicle) !=
        m_ownedVehicles.end();
}

bool Company::beginDelivery(Vehicle *vehicle, std::string destination) {
    return true;
}
