#include "Option.h"
#include <iostream>
#include <string>

class BuyFuelOption : public Option {

public:
    std::string getName() override { return "Buy fuel"; }

    void execute(Company *company) override { std::cout << "Buy fuel logic here" << std::endl; }
};
