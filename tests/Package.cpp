#include "../Package.h"
#include "../Destination.h"
#include <cassert>

int main() {
    Destination destination = Destination("Canberra", 800, true, true, true);
    Package package = Package("Shoes", destination, 20);
    assert(package.getDestination().equals(destination));
    assert(package.getDescription() == "Shoes");
    assert(package.getWeight() == 20);
}
