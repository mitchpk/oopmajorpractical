#include "../Company.h"
#include <cassert>

int main() {
    // Test Company class here
    Company myCompany("Amazon", 23);
    assert(myCompany.getName() == "Amazon");
    assert(myCompany.getBalance() == 23);
    assert(!myCompany.isBankrupt());
    myCompany.addFunds(10);
    assert(myCompany.getBalance() == 33);
    myCompany.subractFunds(5);
    assert(myCompany.getBalance() == 28);
    myCompany.setBalance(100);
    assert(myCompany.getBalance() == 100);

    return 0;
}
