#include "Dog.hpp"

Dog::Dog(): Animal(){
    std::cout << "Dog : Default Constructor " << std::endl;
    _brain = new Brain();
    _type = "Dog";
};

Dog::Dog(const std::string &type): Animal(type){
    std::cout << "Dog : Name Constructor " << std::endl;
    _brain = new Brain();
    this->_type = type;
};

Dog::Dog(const Dog &copy): Animal(copy){
    std::cout << "Dog : Copy Constructor " << std::endl;
    _brain = new Brain();
    *this = copy;
};

Dog     &Dog::operator=(const Dog &copy){
    std::cout << "Dog : Copy Assignment Operator " << std::endl;
    if (this != &copy)
    {
        delete (this->_brain);
        this->_brain = new Brain(*copy._brain);
        this->_type = copy._type;
    }
    return (*this);
};

Dog::~Dog(){
    std::cout << "Dog : Destructor " << std::endl;
};

void    Dog::makeSound() const {
    std::cout << "Dog Sound" << std::endl;
};

Brain     *Dog::getBrain() const {
    return (this->_brain);
};