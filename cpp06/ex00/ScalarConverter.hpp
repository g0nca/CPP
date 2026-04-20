#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cfloat>

enum ScalarDetectType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(std::string );
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();

        ScalarConverter &operator=(const ScalarConverter &copy);

        static ScalarDetectType detectType(const std::string &str);

        static  bool    isChar(const std::string &str);
        static  bool    isInt(const std::string &str);
        static  bool    isFloat(const std::string &str);
    public:


        static void    convert(const std::string &str);

        class IsEmpty : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("String is empty");
                }
        };
        class InvalidFloatNumber : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Invalid float number");
                }
        };
};
