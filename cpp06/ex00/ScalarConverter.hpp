#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cfloat>
#include <iomanip>

enum ScalarDetectType
{
    PSEUDO, //0
    CHAR,   //1
    INT,    //2
    FLOAT,  //3
    DOUBLE, //4
    INVALID //5
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
        static  bool    isDouble(const std::string &str);
        static  bool    isPseudoLiteral(const std::string &str);

        static void     convertChar(const std::string &);
        static void     convertInt(const std::string &);
        static void     convertFloat(const std::string &);
        static void     convertDouble(const std::string &);
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
        class InvalidFormat : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Invalid Format");
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
        class InvalidSignals : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Too much Signals");
                }
        };
        class MultipleDotsOrNone : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Multiple dots or none");
                }
        };
        class InvalidDoubleNumber : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Invalid double number");
                }
        };
};
