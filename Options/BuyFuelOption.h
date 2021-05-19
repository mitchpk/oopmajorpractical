#include <iostream>
#include "Option.h"
#include <string>


class BuyFuelOption : public Option
{

public:
    BuyFuelOption()
    {
        Option::Name = "Buy fuel.";
    }

    void execute()
    {
        std::cout << "Buy fuel logic here";
    }


};