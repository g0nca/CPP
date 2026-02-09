
#pragma once

#include <iostream>
#include <iomanip>
#include <string>


class Weapon
{
    private:
        std::string _type;

    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        std::string const   &getType(void);
        void    setType(std::string type);
};