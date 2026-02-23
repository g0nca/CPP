#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string newName);
        FragTrap(const FragTrap &copy);
        ~FragTrap();

        FragTrap &operator=(const FragTrap &copy);
        void    highFivesGuys(void);
};