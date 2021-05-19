#include <string>
#pragma once


class Option
{

public:

    std::string Name;
    std::string getName();
    virtual void execute();

};