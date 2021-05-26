#pragma once
#include <vector>
#include <string>

#include "Fuel.h"
#include "Vehicle.h"

// Represents the user's company, including their assets in vehicles and current balance
class Company {
public:
    Company(std::string name, int startingBalance);
    ~Company();

    std::string getName();

    int getBalance();

    // Purchase a vehicle, returns true if the vehicle has been bought, false if insufficient balance
    bool purchaseVehicle(Vehicle *vehicle);

    // Initiate a delivery to a given destination, checks whether the vehicle is of the correct type
    bool beginDelivery(Vehicle *vehicle, std::string destination);

    // Check to see if the company owns a given vehicle
    bool ownsVehicle(Vehicle *vehicle);

    // Get all owned vehicles
    std::vector<Vehicle*> getVehicles();

    // Get current balance
    bool isBankrupt();

    //Sets the balance of the company
    void setBalance(int amount);

    //Adds to company balance
    void addFunds(int amount);

    //Subtracts from company balance
    void subractFunds(int amount);

private:
    int m_balance;
    std::string m_name;
    std::vector<Vehicle*> m_ownedVehicles;
    bool m_bankrupt;
};
