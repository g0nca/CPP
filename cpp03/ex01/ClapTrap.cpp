#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Default Constructor Called" << std::endl;
};

ClapTrap::ClapTrap(std::string name):  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Name Constructor Called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &copy){
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
};

ClapTrap    &ClapTrap::operator=(const ClapTrap &copy){
    std::cout << "Assignment Operator Called" << std::endl;
    if (this != &copy)
    {
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return (*this);
};

ClapTrap::~ClapTrap(){
    std::cout << "Destructor Called" << std::endl;
};

void    ClapTrap::attack(const std::string& target){
    if (_energyPoints > 0 && _attackDamage > 0)
    {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _hitPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy or hit points" << std::endl;
    }
};

void    ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints > 0)
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already destroyed" << std::endl;
    }
};


void    ClapTrap::beRepaired(unsigned int amount){
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy or already destroyed!" << std::endl;
    }
};

void    ClapTrap::setName(std::string newName){
    _name = newName;
};

void    ClapTrap::displayInfo(void){
    std::cout << "Name [ " << _name << " ] --> Heatlh [ " << _hitPoints << " ] --> Energy [ " << _energyPoints << "] --> Attack [ " << _attackDamage << " ]" << std::endl;
};