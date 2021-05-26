#include <iostream>
#include "Option.h"
#include <string>
#include <random>


class SendVehicleOption : public Option
{
public:
    std::string getName() override {
        return "Send a vehicle";
    }

    void execute(Company *company) override {
        std::cout << "Choose a vehicle to send out:\n";
        bool canSend = false;
        std::vector<Vehicle*> vehicles = company->getVehicles();
        for (int i = 0; i < vehicles.size(); i++) {
            if (vehicles[i]->getPackages().size() > 0) {
                canSend = true;
                std::cout << i+1 << ". " << vehicles[i]->getName() << std::endl;
            }
        }

        if (!canSend) {
            std::cout << "None of your vehicles have packages loaded\n";
            return;
        }

        std::string selectedVehicle;
        std::cin >> selectedVehicle;
        if (Option::is_number(selectedVehicle)) {
            int selected = std::stoi(selectedVehicle);
            if (selected <= vehicles.size() && selected > 0) {
                if (vehicles[selected-1]->getPackages().size() > 0) {
                    vehicles[selected-1]->travel();
                    std::cout << "Sent vehicle" << std::endl;
                }
            }
        } 
    }
};
