#pragma once

#include <string>
#include <iostream>
template<typename T>class   Array
{
    private:
        T*              _array;
        unsigned int    _length;
    public:
        Array(void): _array(NULL), _length(0) {};
        Array(unsigned int n): _array(new T[n]()), _length(n) {};
        Array(const Array& copy): _array(NULL), _length(0) {
            *this = copy;
        };
        Array   &operator=(const Array& copy){
            if (this != &copy)
            {
                if (this->_array != NULL)
                    delete[] this->_array;
                this->_length = copy.size();
                this->_array = new T[this->_length]();
                for (unsigned int i = 0; i < this->_length; i++)
                    this->_array[i] = copy._array[i];
            }
            return (*this);
        };
        T&   operator[](unsigned int index){
            if (index >= size())
                throw Array::OutOfBoundsException();
            return (this->_array[index]);
        }
        ~Array(){
            delete[] _array;
        };

        unsigned int size() const
        {
            return (this->_length);
        }

        class OutOfBoundsException : public std::exception 
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Index is out of bounds!");
                }
        };
};
