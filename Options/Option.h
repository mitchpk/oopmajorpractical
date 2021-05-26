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

    // https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
    static bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
};
