#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    std::cout << "WrongCat : Default Constructor" << std::endl;
    this->_type = "WrongCat";
};

WrongCat::WrongCat(const std::string &type): WrongAnimal(type){
    std::cout << "WrongCat : Name Constructor" << std::endl;
    this->_type = type;
};

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy){
    std::cout << "WrongCat : Copy Constructor" << std::endl;
};

WrongCat::~WrongCat(){
    std::cout << "WrongCat : Destructor" << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &copy){
    std::cout << "WrongCat : Copy Assignment Operator" << std::endl;
    if (this != &copy)
    {
        *this = copy;
    }
    return (*this);
};

void    WrongCat::makeSound() const {
    std::cout << "WrongCat Sound" << std::endl; 
};

