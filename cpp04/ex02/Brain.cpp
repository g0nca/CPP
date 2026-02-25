#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain : Default COnstructor " << std::endl;
};

Brain::Brain(const Brain &copy){
    std::cout << "Brain : Copy Constructor " << std::endl;
    *this = copy;
};

Brain::~Brain(){
    std::cout << "Brain : Destructor " << std::endl;
};

Brain   &Brain::operator=(const Brain &copy){
    std::cout << "Brain : Copy Assignment" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = copy._ideas[i];
    }
    return (*this);
};

std::string     Brain::getIdea(int id) const {
    return (this->_ideas[id]);
};

void    Brain::setIdea(int id, std::string str){
    this->_ideas[id] = str;
};