#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
}

HumanA::~HumanA()
{
}

void    attack()
{
    std::cout << this->_name << "attacks with their " << this->_weapon.getType() << std::endl;
}
