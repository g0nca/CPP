#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cfloat>

class ScalarConverter
{
    public:
        ScalarConverter(void);
        ScalarConverter(std::string );
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();

        ScalarConverter &operator=(const ScalarConverter &copy);

        static void    convert(std::string str);
};
