#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}

std::string const &Weapon::getType(void)
{
    return (this->_type);
}