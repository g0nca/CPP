#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << "Default ScavTrap Construtor Called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName){
    std::cout << "ScavTrap - Name Constructor Called " << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy){
    std::cout << "ScavTrap -Copy Constructor Called" << std::endl;
    //*this = copy;
};

ScavTrap    &ScavTrap::operator=(const ScavTrap &copy){
    std::cout << "ScavTrap - Assignment Operator Called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return (*this);
};

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor Called" << std::endl;
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