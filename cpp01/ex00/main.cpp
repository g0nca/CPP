
#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    std::string ZombieName;

    std::cout << "What's Zombie name: ";
    std::getline(std::cin, ZombieName);
    zombie = newZombie(ZombieName);
    if (!zombie)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (1);
    }
    zombie->announce();
    delete(zombie);
    randomChump(ZombieName);
    return (0);
}