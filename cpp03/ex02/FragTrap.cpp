#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "Default Constructor Called" << std::endl;
    std::cout << "FragTrap " << this->_name << " is on !" <<std::endl;
};

FragTrap::FragTrap(std::string newName): ClapTrap(newName) {
    this->_name = newName;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Constructor with name Called" << std::endl;
    std::cout << "FragTrap " << this->_name << " is on !" << std::endl;
};

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    std::cout << "FragTrap " << this->_name << " is on!" << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return (*this);
};

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " is off!" << std::endl;
    std::cout << "FragTrap destructor called" << std::endl;
};

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " : high five !" << std::endl;
};