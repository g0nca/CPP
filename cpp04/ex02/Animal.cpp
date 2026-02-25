#include "Animal.hpp"

Animal::Animal(): _type("default"){
    std::cout << "Animal : Default Constructor" << std::endl;
};

Animal::Animal(const std::string &type): _type(type) {
    std::cout << "Animal : Name Constructor" << std::endl;
};

Animal::Animal(const Animal &copy){
    std::cout << "Animal : Copy Object" << std::endl;
    *this = copy;
};

Animal  &Animal::operator=(const Animal &copy){
    std::cout << "Animal : Assignment Operator Called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
};

Animal::~Animal(){
    std::cout << "Animal : Destructor" << std::endl;
};

std::string Animal::getType() const {
    std::cout << "Animal : getType method ";
    return (this->_type);
};

void    Animal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
};