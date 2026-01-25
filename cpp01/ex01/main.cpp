
#include "Zombie.hpp"

int main(void)
{
    std::string zombieName;
    int         numberOfZombies = 0;
    bool        validInput = false;

    while (validInput == false)
    {
        std::cout << "How many zombies do you want to create (from 0 ti 250) : ";
        std::cin >> numberOfZombies;
        if (numberOfZombies <= 0 || numberOfZombies > 250)
        {
            std::cout << "Invalid quantity. Please enter a number between 1 and 250." << std::endl;
        }
        else
        {
            validInput = true;
        }
    }
    std::cout << "Name your Zombie: ";
    std::cin >> zombieName;
    Zombie *Horde = zombieHorde(numberOfZombies, zombieName);
    if (!Horde)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (1);
    }
    for (int i = 0; i < numberOfZombies; i++)
    {
        Horde[i].announce();
    }
    delete[] Horde;
    return (0);
}