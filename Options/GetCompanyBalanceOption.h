#include <iostream>
#include "Option.h"
#include <string>


class GetCompanyBalanceOption : public Option
{
public:
    // option "get company balance"
    std::string getName() override {
        return "Get company balance";
    }

    // when selected returns company balance
    void execute(Company *company) override {
        std::cout << "Company balance: " << company->getBalance() << std::endl;
    }
};
