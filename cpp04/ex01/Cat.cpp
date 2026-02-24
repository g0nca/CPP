#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal(){
    std::cout << "Cat : Default Constructor " << std::endl;
    _brain = new Brain();
    this->_type = "Cat";
};

Cat::Cat(const std::string &type): Animal(type){
    std::cout << "Cat : Name Constructor " << std::endl;
    _brain = new Brain();
    this->_type = type;
};

Cat::Cat(const Cat &copy): Animal(copy){
    std::cout << "Cat : Copy Constructor " << std::endl;
    _brain = new Brain();
    *this = copy;
};

Cat::~Cat(){
    std::cout << "Cat : Desctructor " << std::endl;
};

Cat     &Cat::operator=(const Cat &copy){
    std::cout << "Cat : Copy Assignment Operator " << std::endl;
    if (this != &copy)
    {
        delete (this->_brain);
        this->_brain = new Brain(*copy._brain);
        this->_type = copy._type;
    }
    return (*this);
};

void    Cat::makeSound() const {
    std::cout << "Cat Sound" << std::endl;
};

Brain   *Cat::getBrain() const {
    return (this->_brain);
};