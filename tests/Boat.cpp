#include <string>
#include <cassert>

#include "../Vehicle.h"
#include "../Fuel.h"
#include "Ship.h"

int main() {


    // Test Aircraft/vehicles here
    Fuel unleaded = Fuel(2.0f, "Unleaded Fuel 808", Fuel::TRUCK, 3);
    Ship titanic = Ship("Titanic", 333, 3333, 3.3f, 33000, unleaded);

    assert(titanic.getName() == "Titanic");

    //should assert false
    assert(titanic.getFuelCapacity() == 333);

    return 0;
}