#pragma once
#include <iostream>
#include <string>

class Brain
{
    private:
        std::string     _ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();

        Brain   &operator=(const Brain &copy);

        std::string     getIdea(int id) const;
        void            setIdea(int id, std::string str);

};