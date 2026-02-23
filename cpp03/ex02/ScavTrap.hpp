#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string newName);
        ScavTrap(const ScavTrap& copy);
        ~ScavTrap();

        ScavTrap    &operator=(const ScavTrap &copy);

        void    attack(const std::string &target);
        void    guardGate();
};