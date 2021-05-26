#include <string>
#include <cassert>

#include "../Vehicle.h"
#include "../Fuel.h"
#include "Truck.h"

int main() {


    // Test Aircraft/vehicles here
    Fuel unleaded = Fuel(2.0f, "Unleaded Fuel 808", Fuel::TRUCK, 3);
    Truck monstertruck = Truck("Monster Truck", 333, 3333, 3.3f, 33000, unleaded);

    assert(monstertruck.getName() == "Monster Truck");

    assert(monstertruck.getFuelCapacity() == 333);

    return 0;
}