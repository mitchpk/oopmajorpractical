#pragma once
#include <string>
#include <iostream>
#include "../Company.h"

class Option {
public:
    virtual std::string getName() = 0;
    virtual void execute(Company *company) = 0;
};
