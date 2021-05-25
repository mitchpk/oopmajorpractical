#include "Option.h"
#include <iostream>
#include <string>

class BuyFuelOption : public Option {

public:
    // option "buy fuel"
    std::string getName() override { return "Buy fuel"; }

    // when selected allows fuel to be purchased
    void execute(Company *company) override { std::cout << "Buy fuel logic here" << std::endl; }
};
