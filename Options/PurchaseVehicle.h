#include "Option.h"
#include <iostream>
#include <string>

class PurchaseVehicleOption : public Option {

public:
    // option "purchase vehicle"
    std::string getName() override { return "Purchase vehicle"; }
    PurchaseVehicleOption(std::vector<Vehicle*> *vehicles) : m_vehicles(vehicles) {}

    // when selected allows vehicles to be purchased
    void execute(Company *company) override { 
        std::cout << "Vehicles in store:\n";
        for (int i = 0; i < m_vehicles->size(); i++) {
            auto vehicle = (*m_vehicles)[i];
            if (!company->ownsVehicle(vehicle)) {
                std::cout << i+1 << ". " << vehicle->getName() << ": $" << vehicle->getPrice(); 
                std::string type = "";
                switch (vehicle->getType()) {
                    case Vehicle::AIRCRAFT:
                        type = "Aircraft";
                        break;
                    case Vehicle::TRUCK:
                        type = "Truck";
                        break;
                    case Vehicle::SHIP:
                        type = "Ship";
                }

                std::cout << " (" << type << ")\n";
            }
        }

        std::string selectedVehicle;
        std::cin >> selectedVehicle;
        if (Option::is_number(selectedVehicle)) {
            int selected = std::stoi(selectedVehicle);
            if (selected <= m_vehicles->size() && selected > 0) {
                if (company->purchaseVehicle((*m_vehicles)[selected - 1]))
                    std::cout << "Successfully purchased vehicle\n";
            }
        } 
    }

private:
    std::vector<Vehicle*> *m_vehicles;
};
