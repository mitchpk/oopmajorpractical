#include <iostream>
#include "Option.h"
#include <string>


class GetCompanyNameOption : public Option
{

public:
    GetCompanyNameOption()
    {
        Option::Name = "Get Company Name";
    }

    void execute()
    {

        std::cout << Name << std::endl;
    }


};