#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const std::string &type);
        Cat(const Cat &copy);
        ~Cat();

        Cat &operator=(const Cat &copy);

        void    makeSound() const;
};