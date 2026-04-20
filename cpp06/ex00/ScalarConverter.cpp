#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){};

ScalarConverter::ScalarConverter(std::string str){
    (void)str;
};

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
};

ScalarConverter::~ScalarConverter(){

};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
    (void)copy;
    return (*this);
};

void     ScalarConverter::convert(const std::string &str) 
{
    try {
        if (str.empty())
            throw(ScalarConverter::IsEmpty());
        ScalarDetectType type = detectType(str);

        std::cout << type << std::endl;
        std::cout << str << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
};

ScalarDetectType    ScalarConverter::detectType(const std::string &str)
{
    if ((str.length() == 1) && isChar(str))
        return CHAR;
    else if (isInt(str))
        return INT;
    else if (((str[str.length() - 1] == 'f') || (str[str.length() - 1] == 'F')) && isFloat(str))
        return FLOAT;

    return (INVALID);
};
bool    ScalarConverter::isChar(const std::string &str)
{
    return (!std::isdigit(str[1]));
};

bool    ScalarConverter::isInt(const std::string &str)
{
    size_t  i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
};

bool    ScalarConverter::isFloat(const std::string &str)
{
    int dot, i = 0;
    const int size = str.length();

    while (i < size && (std::isdigit(str[i]) || (str[i] == '.')))
    {
        if (str[i] == '.')
            dot++;
        if (dot > 1)
            throw (ScalarConverter::InvalidFloatNumber());
        i++;
    }
    return true;
};
