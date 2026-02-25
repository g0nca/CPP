#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &copy);
        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &copy);

        void    makeSound() const;
        std::string     getType() const;
};