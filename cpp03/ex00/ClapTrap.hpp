#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class ClapTrap
{
    private :
        std::string     _name;
        unsigned int    _health;
        unsigned int    _energy;
        unsigned int    _attack;

    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &copy);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    displayInfo(void);
        void    setName(std::string name);
};