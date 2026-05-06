#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>

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
        
        template<typename Iterator>
        void    addNumber(Iterator begin, Iterator end)
        {
            unsigned int distance = std::distance(begin, end);

            if (_list.size() + distance > _n)
                throw (Span::MaxValueReached());
            _list.insert(_list.end(), begin, end);
        };

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