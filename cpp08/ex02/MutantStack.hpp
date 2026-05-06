#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack &copy): std::stack<T>(copy){};
        MutantStack& operator=(const MutantStack &copy){
            if (this != &copy){
                std::stack<T>::operator=(copy);
            }
            return (*this);
        }
        ~MutantStack(){};

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin( void ) {
            return (this->c.begin());
        }

        iterator end( void ){
            return (this->c.end());
        }
};