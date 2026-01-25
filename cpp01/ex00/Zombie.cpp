
#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    _name = name;
}

Zombie::~Zombie(){
    std::cout << "Zombie " << this->_name << " is dead" << std::endl;
}

void    Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
