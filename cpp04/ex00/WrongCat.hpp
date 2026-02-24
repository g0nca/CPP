#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const std::string &type);
        WrongCat(const WrongCat &copy);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &copy);

        void    makeSound() const;
};