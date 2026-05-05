#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>

class   Span
{
    private:
        unsigned int            _n;
        std::vector<int>        _list;
    public:
        Span();
        Span(unsigned int number);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void    addNumber(int n);
        void    addMultipleNumbers(int n);
        int     shortestSpan();
        int     longestSpan();

        void    printSpan() const;
        
        class MaxValueReached : public std::exception
        {
            public:
                const char *what() const throw(){
                    return ("Max values reached");
                }
        };

        class NotEnoughNumbers: public std::exception
        {
            public:
                const char *what() const throw(){
                    return ("Not enough numbers");
                }
        };
};