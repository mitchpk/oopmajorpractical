#include "Option.h"
#include <iostream>
#include <string>

class BuyFuelOption : public Option {

public:
    // option "buy fuel"
    std::string getName() override { return "Buy fuel"; }

    BuyFuelOption(std::vector<Fuel> fuels) : m_fuels(fuels) {}

    // when selected allows fuel to be purchased
    void execute(Company *company) override { 
        if (company->getVehicles().size() < 1) return;
        std::cout << "Choose a vehicle to refill fuel:\n";
        std::vector<Vehicle*> vehicles = company->getVehicles();
        for (int i = 0; i < vehicles.size(); i++) {
            std::cout << i+1 << ". " << vehicles[i]->getName() << std::endl;
        }

        std::string selectedVehicle;
        std::cin >> selectedVehicle;
        if (Option::is_number(selectedVehicle)) {
            int selected = std::stoi(selectedVehicle);
            if (selected <= vehicles.size() && selected > 0) {
                if (vehicles[selected-1]->getRemainingFuel() == vehicles[selected-1]->getFuelCapacity()) {
                    std::cout << "This vehicle is already full of fuel\n";
                    return;
                }
                auto fuelType = vehicles[selected-1]->getFuelType();
                std::cout << "Choose a fuel:\n";
                for (int i = 0; i < m_fuels.size(); i++) {
                    if (m_fuels[i].type == fuelType) {
                        std::cout << i+1 << ". " << m_fuels[i].name << " (efficiency " << m_fuels[i].efficiency << "), price per unit: " << m_fuels[i].pricePerUnit << std::endl;
                    }
                }

                std::string selectedFuel;
                std::cin >> selectedFuel;
                if (Option::is_number(selectedFuel)) {
                    int selected2 = std::stoi(selectedFuel);
                    if (selected2 <= m_fuels.size() && selected2 > 0) {
                        if (vehicles[selected-1]->buyFuel(m_fuels[selected2-1]))
                            std::cout << "Purchased fuel\n";
                    }
                }
            }
        } 

    }

private:
    std::vector<Fuel> m_fuels;
};
