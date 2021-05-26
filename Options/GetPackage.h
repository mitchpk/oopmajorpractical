#include <iostream>
#include "Option.h"
#include <string>
#include <random>


class GetPackageOption : public Option
{
public:
    GetPackageOption(std::vector<Package> packages, std::vector<Destination> destinations) : m_packages(packages), m_destinations(destinations) {}

    // option "get company name"
    std::string getName() override {
        return "Get a package";
    }

    // when selected prints company name
    void execute(Company *company) override {
        srand(time(NULL));
        Package chosenPackage = m_packages[rand() % m_packages.size()];
        Destination chosenDestination = m_destinations[rand() % m_destinations.size()];
        chosenPackage.setDestination(chosenDestination);
        std::cout << "New package: " << chosenPackage.getDescription() << std::endl;
        std::cout << "Destination: " << chosenDestination.getName() << " (" << chosenDestination.getDistance() << " km)\n";
        std::cout << "Choose a vehicle to load this package into:" << std::endl;
        
        std::vector<Vehicle*> vehicles = company->getVehicles();
        bool canShip = false;
        for (int i = 0; i < vehicles.size(); i++) {
            if (chosenDestination.vehicleCanReach(vehicles[i])) {
                canShip = true;
                std::cout << i+1 << ". " << vehicles[i]->getName() << std::endl;
            }
        }

        if (!canShip) {
            std::cout << "You have no vehicles which can ship to this destination" << std::endl;
        } else {
            std::string selectedVehicle;
            std::cin >> selectedVehicle;
            if (Option::is_number(selectedVehicle)) {
                int selected = std::stoi(selectedVehicle);
                if (selected <= vehicles.size() && selected > 0) {
                    auto packages = vehicles[selected-1]->getPackages();
                    if (packages.size() > 0) {
                        if (!packages[0].getDestination().equals(chosenDestination)) {
                            std::cout << "You already have a loaded package with a different destination\n";
                            return;
                        }
                    }
                    if (chosenDestination.vehicleCanReach(vehicles[selected-1])) {
                        vehicles[selected-1]->loadPackage(chosenPackage);
                        std::cout << "Loaded package" << std::endl;
                    }
                }
            } 
        }
    }

private:
    std::vector<Package> m_packages;
    std::vector<Destination> m_destinations;
};
