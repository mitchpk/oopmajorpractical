#include "Company.h"
#include <algorithm>

Company::Company(std::string name, int startingBalance) {
    m_name = name;
    m_balance = startingBalance;
    m_bankrupt = false;
}

Company::~Company() {
    for (auto v : m_ownedVehicles) {
        delete v;
    }
}

std::string Company::getName()
{
    return Company::m_name;
}

int Company::getBalance()
{
    return Company::m_balance;
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

bool Company::isBankrupt() {

    return m_bankrupt;
}

std::vector<Vehicle*> Company::getVehicles() {
    return m_ownedVehicles;
}

void Company::setBalance(int amount)
{
    Company::m_balance = amount;
}

void Company::addFunds(int amount)
{
    Company::m_balance = m_balance + amount;
}

void Company::subractFunds(int amount)
{
    Company::m_balance = m_balance - amount;

    if( m_balance - amount < 0)
    {
        Company::m_balance = 0;
        Company::m_bankrupt = true;
    }
}
