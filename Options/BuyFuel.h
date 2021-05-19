#include <iostream>
#include "Option.h"
#include <string>


class BuyFuel : public Option
{

public:
    BuyFuel()
    {
        Option::Name = "Buy fuel.";
    }

    void execute()
    {

    }


};