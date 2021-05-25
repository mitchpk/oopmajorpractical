#pragma once
#include <string>
#include <iostream>
#include "../Company.h"

// class to use to allow user inputs
class Option {
public:
    // pure virtual functions to be defined by child classes
    virtual std::string getName() = 0;
    virtual void execute(Company *company) = 0;
};
