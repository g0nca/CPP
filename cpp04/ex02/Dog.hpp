#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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