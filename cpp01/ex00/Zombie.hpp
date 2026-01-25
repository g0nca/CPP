#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        void    announce(void);
        Zombie(std::string name);
        ~Zombie();
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);