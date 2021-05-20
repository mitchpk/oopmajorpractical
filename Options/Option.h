#include <string>
#include <iostream>
#pragma once


class Option
{

public:

    std::string Name;
    std::string getName();
    virtual void execute() = 0;
};
