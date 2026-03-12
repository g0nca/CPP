#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _health(10), _energy(10), _attack(0){
    std::cout << "Default Constructor Called" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack(10){
    std::cout << "Name Constructor Called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &copy) /*_name(copy._name), _health(copy._health), _energy(copy._energy), _attack(copy._attack)*/{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
};

ClapTrap    &ClapTrap::operator=(const ClapTrap &copy){
    std::cout << "Assignment Operator Called" << std::endl;

    if (this != &copy)
    {
        _name = copy._name;
        _health = copy._health;
        _energy = copy._energy;
        _attack = copy._attack;
    }
    return (*this);
};

ClapTrap::~ClapTrap(){
    std::cout << "Destructor Called" << std::endl;
};




void    ClapTrap::attack(const std::string& target){
    if (_attack > 0 && _energy > 0)
    {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy or hit points" << std::endl;
    }
};

void    ClapTrap::takeDamage(unsigned int amount){
    if (_health > 0)
    {
        _health -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already destroyed" << std::endl;
    }
};

void    ClapTrap::beRepaired(unsigned int amount){
    if (_health > 0 && _energy > 0)
    {
        _health += amount;
        _energy--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points spending 1 energy point" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy or already destroyed!" << std::endl;
    }
};




void    ClapTrap::displayInfo(void){
    std::cout << "Name [ " << _name << " ] --> Heatlh [ " << _health << " ] --> Energy [ " << _energy << "] --> Attack [ " << _attack << " ]" << std::endl;
};

void    ClapTrap::setName(std::string name){
    _name = name;
};
