#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &copy);
        virtual ~Animal();

        Animal &operator=(const Animal &copy);

        std::string getType() const;
        virtual void    makeSound() const;
};