#include <iostream>
#include "Option.h"
#include <string>


class GetCompanyName : public Option
{

public:
    GetCompanyName()
    {
        Option::Name = "Get Company Name";
    }

    void execute()
    {

        std::cout << Name << std::endl;
    }


};