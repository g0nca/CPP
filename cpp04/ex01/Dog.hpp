#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain   *_brain;
    public:
        Dog();
        Dog(const std::string &type);
        Dog(const Dog &copy);
        ~Dog();

        Dog &operator=(const Dog &copy);

        void    makeSound() const;
        Brain     *getBrain() const;
};