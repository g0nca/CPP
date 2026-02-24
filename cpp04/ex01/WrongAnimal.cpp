#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Default"){
    std::cout << "WrongAnimal : Default Constructor " << std::endl;
};

WrongAnimal::WrongAnimal(const std::string &type): _type(type){
    std::cout << "WrongAnimal : Name Constructor " << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
    std::cout << "WrongAnimal : Copy Constructor " << std::endl;
    *this = copy;
};

WrongAnimal     &WrongAnimal::operator=(const WrongAnimal &copy){
    std::cout << "WrongAnimal : Copy Assignment Operator " << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
};

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal : Destructor " << std::endl;
};

void    WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal Sound" << std::endl;
};

std::string     WrongAnimal::getType() const {
    return(this->_type);
};