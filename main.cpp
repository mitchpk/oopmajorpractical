#include "Company.h"
#include "Destination.h"
#include "Package.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Ship.h"
#include "Aircraft.h"
#include <iostream>

#include "Options/BuyFuel.h"
#include "Options/GetCompanyBalance.h"
#include "Options/GetCompanyName.h"
#include "Options/PurchaseVehicle.h"

// initialise array of destinations to deliver to
std::vector<Destination> destinations = {
    Destination("London", 3000, true, false, true),
    Destination("Sydney", 1000, true, true, false),
    Destination("Adelaide", 200, true, true, true),
    Destination("Melbourne", 800, true, true, true),
    Destination("Perth", 1400, true, true, true),
    Destination("Rome", 2800, true, false, false),
    Destination("Beijing", 1200, true, false, false),
    Destination("Alice Springs", 1200, true, true, false),
};

// initialise array of packages to be delivered
std::vector<Package> packages = {
    Package("Teacups", 5),
    Package("Book", 2),
    Package("Dumbells", 11),
    Package("Playstation", 6),
    Package("Television", 7),
    Package("IKEA Flat-pack House", 34),
};

std::vector<Fuel> fuels = {
    Fuel(0.3, "Basic Diesel", Fuel::TRUCK, 2),
    Fuel(0.7, "Advanced Diesel", Fuel::TRUCK, 15),
    Fuel(1, "Turbodiesel", Fuel::TRUCK, 20),
    Fuel(0.5, "Basic Jet Fuel", Fuel::AIRCRAFT, 10),
    Fuel(0.8, "Commercial Grade Jet Fuel", Fuel::AIRCRAFT, 18),
    Fuel(1.2, "Military Grade Jet Fuel", Fuel::AIRCRAFT, 24),
    Fuel(0.4, "Basic Ship Fuel", Fuel::SHIP, 7),
    Fuel(0.7, "Advanced Ship Fuel", Fuel::SHIP, 12),
    Fuel(1, "Cargo Freighter Ship Fuel", Fuel::SHIP, 15),
};

std::vector<Vehicle*> vehicles = {
    new Truck("Ute", 60, 20, 1, 3000, fuels[0]),
    new Truck("18-gear Monstrosity", 100, 60, 0.8, 8000, fuels[1]),
    new Ship("Little Yacht", 50, 30, 1, 4000, fuels[6]),
    new Ship("Cargo Ship", 90, 100, 0.9, 9000, fuels[7]),
    new Aircraft("Cessna Propellorhead", 120, 20, 1, 5000, fuels[3]),
    new Aircraft("F Super Hornet", 240, 50, 0.9, 9000, fuels[4]),
};

const std::string welcome =
        "Welcome to Courier Simulator! \nIn this game, you will "
        "manage and expand your own delivery company, shipping packages "
        "all over the world!\nTo begin, enter the name of your company: ";

// function to list all owned vehicles by company in parameter
void listVehicles(Company &company) {
    for (Vehicle *v : company.getVehicles()) {
        // prints information about owned vehicles
        std::cout << v->getName() << std::endl;
        std::cout << "Fuel burn rate: " << v->getFuelBurnRate() << std::endl;
        std::cout << "Remaining fuel: " << v->getRemainingFuel() << std::endl;
        std::cout << "Fuel capacity: " << v->getFuelCapacity() << std::endl;
        if (v->getPackages().size() > 0)
            std::cout << "Loaded packages: " << std::endl;
        // loops through all loaded packages and prints information
        for (Package p : v->getPackages()) {
            Destination d = p.getDestination();
            std::cout << p.getDescription() << " - " << d.getName() << " ("
                                << d.getDistance() << " km)" << std::endl;
        }
        std::cout << std::endl;
    }
}

std::vector<Option *> generateOptions() {

    // define options here (could move to make more tidy)

    std::vector<Option *> options;

    options.push_back(new PurchaseVehicleOption(&vehicles));
    options.push_back(new BuyFuelOption());

    // end of defining options

    return options;
}

//function to print selectable options
void printOptions(std::vector<Option *> options) {
    for (int i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options[i]->getName() << std::endl;
    }
}

int main() {
    std::cout << welcome << std::endl;
    std::string desiredName;
    std::getline(std::cin, desiredName);
    // company now starts with $5000 so they can buy a basic truck
    Company company(desiredName, 5000);

    std::cout << "Great, your company " << company.getName() << " is ready to go."
                        << std::endl;
    std::cout << "Your company will start with: $" << company.getBalance() << std::endl;
    std::cout << "Check the menu below to see your options." << std::endl;

    std::string selectedOption;
    while (!company.isBankrupt()) {
        // runs loop through options
        std::cout << std::endl << std::endl;
        std::cout << "-- Current Balance --" << std::endl;
        std::cout << "$" << company.getBalance() << std::endl;

        std::cout << "-- Company Vehicles --" << std::endl;
        listVehicles(company);

        std::cout << "-- Options --" << std::endl;
        printOptions(generateOptions());

        std::cin >> selectedOption;
        if (Option::is_number(selectedOption)) {
            // check if option is in range
            // selected option works because +1 is the size of the vector
            // because we are printing out index of option +1
            int selected = std::stoi(selectedOption);
            if (selected <= generateOptions().size() && selected > 0) {
                // now you execute the option selected
                generateOptions()[selected - 1]->execute(&company);

            } else {
                std::cout << "Invalid option" << std::endl;
            }
        } else {
            std::cout << "Invalid option" << std::endl;
        }
    }

    return 0;
}
