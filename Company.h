#pragma once
#include <vector>
#include <string>

#include "Fuel.h"
#include "Vehicle.h"

// Represents the user's company, including their assets in vehicles and current balance
class Company {
public:
    Company(std::string name);
    ~Company();

    // Purchase a vehicle, returns true if the vehicle has been bought, false if insufficient balance
    bool purchaseVehicle(Vehicle *vehicle);

    // Purchase some fuel 
    // Returns true or false depending on the type of fuel, maximum capacity of the vehicle and current company balance
    bool purchaseFuel(Vehicle *vehicle, Fuel fuel, int quantity);

    // Initiate a delivery to a given destination, checks whether the vehicle is of the correct type
    bool beginDelivery(Vehicle *vehicle, std::string destination);

    // Check to see if the company owns a given vehicle
    bool ownsVehicle(Vehicle *vehicle);

private:
    int m_balance;
    std::string m_name;
    std::vector<Vehicle*> m_ownedVehicles;
};
