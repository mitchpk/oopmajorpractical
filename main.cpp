#include <iostream>
#include "Package.h"
#include "Destination.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Company.h"

const Destination destinations[] = {
    Destination("London", 3000, true, false, true)
};

const Package packages[] = {
    Package("Teacups", destinations[0], 5)
};

const std::string welcome = 
    "Welcome to <insert game name here>! \nIn this game, you will "
    "manage and expand your own delivery company, shipping packages "
    "all over the world!\nTo begin, enter the name of your company: ";

void listVehicles(Company &company) {
    for (Vehicle *v : company.getVehicles()) {
        std::cout << v->getName() << std::endl;
        std::cout << "Fuel burn rate: " << v->getFuelBurnRate() << std::endl;
        std::cout << "Total fuel capacity" << v->getFuelCapacity() << std::endl;
        std::cout << "Loaded packages: " << std::endl;
        for (Package p : v->getPackages()) {
            Destination d = p.getDestination();
            std::cout << p.getDescription() << " - " << d.getName() << " (" << d.getDistance() << " km)" << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << welcome << std::endl;
    std::string desiredName;
    std::cin >> desiredName;
    Company company(desiredName);

    while (!company.isBankrupt()) {
        listVehicles(company);
        getchar();
    }

    return 0;
}
