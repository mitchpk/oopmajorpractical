#include <iostream>
#include "Package.h"
#include "Destination.h"

const Destination destinations[] = {
    Destination("London", 3000, true, false, true)
};

const Package packages[] = {
    Package("Teacups", destinations[0], 5)
};

int main() {
    std::cout << "Hello" << std::endl;
    return 0;
}
