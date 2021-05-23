#include "Company.h"
#include "Destination.h"
#include "Package.h"
#include "Vehicle.h"
#include <iostream>

#include "Options/BuyFuelOption.h"
#include "Options/GetCompanyBalanceOption.h"
#include "Options/GetCompanyNameOption.h"

const Destination destinations[] = {
    Destination("London", 3000, true, false, true),
    Destination("Sydney", 1000, true, true, false),
    Destination("Adelaide", 200, true, true, true),
    Destination("Melbourne", 800, true, true, true),
    Destination("Perth", 1400, true, true, true),
    Destination("Rome", 2800, true, false, false),
    Destination("Beijing", 1200, true, false, false),
    Destination("Alice Springs", 1200, true, true, false),
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
            std::cout << p.getDescription() << " - " << d.getName() << " ("
                                << d.getDistance() << " km)" << std::endl;
        }
        std::cout << std::endl;
    }
}

std::vector<Option *> generateOptions() {

    // define options here (could move to make more tidy)

    std::vector<Option *> options;

    options.push_back(new GetCompanyNameOption());
    options.push_back(new BuyFuelOption());
    options.push_back(new GetCompanyBalanceOption());

    // end of defining options

    return options;
}

void printOptions(std::vector<Option *> options) {
    for (int i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options[i]->getName() << std::endl;
    }
}

// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main() {
    std::cout << welcome << std::endl;
    std::string desiredName;
    std::cin >> desiredName;
    // company now starts with $5000 so they can buy a basic truck
    Company company(desiredName, 5000);

    std::cout << "Great, your company " << company.getName() << " is ready to go."
                        << std::endl;
    std::cout << "Your company will start with: $" << company.getBalance() << std::endl;
    std::cout << "Check the menu below to see your options." << std::endl;

    std::string selectedOption;
    while (!company.isBankrupt()) {
        // runs loop through options

        std::cout << "-- Company Vehicles --" << std::endl;
        listVehicles(company);

        std::cout << "-- Options --" << std::endl;
        printOptions(generateOptions());

        std::cin >> selectedOption;
        if (is_number(selectedOption)) {
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
