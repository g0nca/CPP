#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << "Default ScavTrap Construtor Called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName){
    std::cout << "ScavTrap with Name Called " << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy){
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
};

ScavTrap    &ScavTrap::operator=(const ScavTrap &copy){
    std::cout << "Assignment Operator Called" << std::endl;
    if (this != &copy)
    {
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return (*this);
};

ScavTrap::~ScavTrap(){
    std::cout << "Destructor Called" << std::endl;
};

void    ScavTrap::attack(const std::string &target){
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
        _energyPoints--;
    }
};

void    ScavTrap::guardGate(){
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "" << std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " cannot enter Gate Keeper Mode !" << std::endl;
    }
};