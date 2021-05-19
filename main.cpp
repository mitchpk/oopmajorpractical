#include <iostream>
#include "Package.h"
#include "Destination.h"
#include "Vehicle.h"
#include "Company.h"

#include "Options/GetCompanyName.h"
#include "Options/BuyFuel.h"
#include "Options/GetCompanyBalanceOption.h"



const Destination destinations[] = {
    Destination("London", 3000, true, false, true),
    Destination("Sydney", 1000, true, true, false),
    Destination("Adelaide", 200, true, true, true),
    Destination("Melbourne", 800, true, true, true),
    Destination("Rome", 2800, true, true, false),
    Destination("Beijing", 1200, true, true, true),
};

const Package packages[] = {
    Package("Teacups", destinations[0], 5),
    Package("Book", destinations[2], 2),
    Package("Dumbells", destinations[3], 11),
    Package("Playstation", destinations[1], 6),
    Package("Televesion", destinations[4], 7),
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

std::vector<Option> declareOptions()
{

     //define options here (could move to make more tidy)

    std::vector<Option> options;

    GetCompanyName gcn;
    BuyFuel bf;
    GetCompanyBalanceOption gcb;

    options.push_back(gcn);
    options.push_back(bf);
    options.push_back(gcb);

    //end of defining options

    return options;
}

int main() {


    std::cout << welcome << std::endl;
    std::string desiredName;
    std::cin >> desiredName;
    //company now starts with $5000 so they can buy a basic truck
    Company company(desiredName, 5000);

    std::cout << "Great, your company " << company.getName() << " is ready to go." << std::endl;
    std::cout << "Your company will start with: $" << company.getBalance() << std::endl;

    std::cout << "Check the menu below to see your options." << std::endl;

    //runs loop through options

    for (int i = 0; i < declareOptions().size(); i++){
        std::cout << i + 1 << ". " << declareOptions()[i].getName() << std::endl;
    }

    while (!company.isBankrupt())
    {
        listVehicles(company);
        getchar();
    }

    return 0;
}
