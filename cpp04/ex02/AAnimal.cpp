#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("Default AAnimal"){
    std::cout << "AAnimal : Default Constructor" << std::endl;
};

AAnimal::AAnimal(const std::string &type): _type(type){
    std::cout << "AAnimal : Type Constructor" << std::endl;
};

AAnimal::AAnimal(const AAnimal &copy){
    std::cout << "AAnimal : Copy Constructor" << std::endl;
    *this = copy;
};

AAnimal::~AAnimal(){
    std::cout << "AAnimal : Destructor" << std::endl;
};

AAnimal     &AAnimal::operator=(const AAnimal &copy){
    std::cout << "AAnimal : Copy Assignment Operator" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
};

std::string AAnimal::getType() const {
    return (this->_type);
};
