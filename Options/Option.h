#include <string>
#include <iostream>
#pragma once


class Option
{

public:

    std::string Name;
    std::string getName();
    virtual void execute()
    {


    //empty because it must be defined by
    //every option

    std::cout << "default option execution" << std::endl;

    }

};