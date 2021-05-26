#include "../Package.h"
#include "../Destination.h"
#include <cassert>

int main() {
    Package package = Package("Shoes", 20);
    assert(package.getDescription() == "Shoes");
    assert(package.getWeight() == 20);
}
