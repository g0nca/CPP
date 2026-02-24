#include "Cat.hpp"

Cat::Cat(): Animal(){
    std::cout << "Cat : Default Constructor " << std::endl;
    this->_type = "Cat";
};

Cat::Cat(const std::string &type): Animal(type){
    std::cout << "Cat : Name Constructor " << std::endl;
    this->_type = type;
};

Cat::Cat(const Cat &copy): Animal(copy){
    std::cout << "Cat : Copy Constructor " << std::endl;
    *this = copy;
};

Cat::~Cat(){
    std::cout << "Cat : Desctructor " << std::endl;
};

Cat     &Cat::operator=(const Cat &copy){
    std::cout << "Cat : Copy Assignment Operator " << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
};

void    Cat::makeSound() const {
    std::cout << "Cat Sound" << std::endl;
};