#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class AAnimal
{
    protected:
        std::string     _type;

    public:
        AAnimal();
        AAnimal(const std::string &type);
        AAnimal(const AAnimal &copy);
        virtual ~AAnimal();

        AAnimal &operator=(const AAnimal &copy);

        virtual void            makeSound() const = 0;
        virtual std::string     getType() const;
};