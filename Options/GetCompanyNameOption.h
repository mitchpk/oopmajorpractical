#include <iostream>
#include "Option.h"
#include <string>


class GetCompanyNameOption : public Option
{
public:
    // option "get company name"
    std::string getName() override {
        return "Get company name";
    }

    // when selected prints company name
    void execute(Company *company) override {
        std::cout << "Company name: " << company->getName() << std::endl;
    }
};
