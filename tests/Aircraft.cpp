#include <string>
#include <cassert>

#include "../Vehicle.h"
#include "../Fuel.h"
#include "Aircraft.h"

int main() {


    // Test Aircraft/vehicles here
    Fuel unleaded = Fuel(2.0f, "Unleaded Fuel 808", Fuel::AIRCRAFT, 3);
    Aircraft sevenfiveseven = Aircraft("Boeing 757", 333, 3333, 3.3f, 33000, unleaded);

    assert(sevenfiveseven.getName() == "Boeing 757");

    assert(sevenfiveseven.getFuelCapacity() == 333);

    return 0;
}