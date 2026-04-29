#pragma once

#include <exception>

class   Utils
{
    public:
        class MissingArguments : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Missing arguments ./Identify <type> <number>");
                }
        };
        class WrongArguments : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Wrong arguments ./Identify <type> <number>");
                }
        };
        class Undefined : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Undefined");
                }
        };
        class NegativeNumber : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Invalid negative numbers");
                }
        };
};