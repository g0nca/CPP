#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class HumanA
{
    private:
        std::string _name;
        Weapon &_weapon;

    public:
        HumanA(std::string name, std::string weapon);
        ~HumanA();
        void    attack();
}