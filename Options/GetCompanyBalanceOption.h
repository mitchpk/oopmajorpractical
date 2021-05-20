#include <iostream>
#include "Option.h"
#include <string>


class GetCompanyBalanceOption : public Option
{

public:
    GetCompanyBalanceOption()
    {
        Option::Name = "Get Company Balance.";
    }

    void execute()
    {
        std::cout << "get company balance logic here" << std::endl;
    }


};
