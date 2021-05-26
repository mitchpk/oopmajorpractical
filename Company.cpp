#include "Company.h"
#include <algorithm>

// Company constructor
Company::Company(std::string name, int startingBalance) {
    m_name = name;
    m_balance = startingBalance;
    m_bankrupt = false;
}

// Company destrutor
Company::~Company() {
    for (auto v : m_ownedVehicles) {
        delete v;
    }
}

// returns name of company
std::string Company::getName()
{
    return Company::m_name;
}

// returns companies balance
int Company::getBalance()
{
    return Company::m_balance;
}


// returns true if vehicle purchased successfully
bool Company::purchaseVehicle(Vehicle *vehicle) { return true; }


// returns true if fuel purchased successfully
bool Company::purchaseFuel(Vehicle *vehicle, Fuel fuel, int quantity) {
    if (ownsVehicle(vehicle)) return true;
    return false;
}

// returns true if the company owns the parameter vehicle
bool Company::ownsVehicle(Vehicle *vehicle) {
    return std::find(m_ownedVehicles.begin(), m_ownedVehicles.end(), vehicle) !=
        m_ownedVehicles.end();
}

// returns true and begins delivery
bool Company::beginDelivery(Vehicle *vehicle, std::string destination) {
    return true;
}

// returns true if company is backrupt
bool Company::isBankrupt() {
    return m_bankrupt;
}

// returns vector of pointers to all owned vehicles
std::vector<Vehicle*> Company::getVehicles() {
    return m_ownedVehicles;
}

// sets the companies balance
void Company::setBalance(int amount)
{
    m_balance = amount;
}

// adds funds to the companies balance
void Company::addFunds(int amount)
{
    m_balance += amount;
}

// subtracts funds from the companies
void Company::subractFunds(int amount)
{
    m_balance -= amount;

    if(m_balance <= 0)
    {
        m_balance = 0;
        m_bankrupt = true;
    }
}
