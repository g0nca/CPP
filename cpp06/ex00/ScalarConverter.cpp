#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){};

ScalarConverter::ScalarConverter(std::string str){
    (void)str;
};

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
};

ScalarConverter::~ScalarConverter(){};

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

        switch (type)
        {
            case CHAR:
                convertChar(str);
                break;
             case INT:
                convertInt(str);
                break;
            case FLOAT:
                convertFloat(str);
                break;
            case DOUBLE:
                convertDouble(str);
                break;
/*            case PSEUDO:
                convertPseudo(str);
                break; */
            default:
                throw(ScalarConverter::InvalidFormat());
        }
        std::cout << std::endl;
        std::cout << "Type : " << type << std::endl;
        std::cout << "String : " << str << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
};

// -------------------------------------------------------------
// --                                                         --
// --               > Detect Type of Input <                  --
// --                                                         --
// -------------------------------------------------------------

ScalarDetectType    ScalarConverter::detectType(const std::string &str)
{
    if ((str.length() == 1) && isChar(str))
        return CHAR;
    else if (isPseudoLiteral(str))
        return PSEUDO;
    else if (isInt(str))
        return INT;
    else if (((str[str.length() - 1] == 'f') || (str[str.length() - 1] == 'F')) && isFloat(str))
        return FLOAT;
    else if (isDouble(str))
        return DOUBLE;
    return (INVALID);
};

bool    ScalarConverter::isChar(const std::string &str)
{
    return (!std::isdigit(str[0]));
};

bool    ScalarConverter::isInt(const std::string &str)
{
    int  i = 0;
    const int   size = str.length();

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < size)
    {
        if (str[i] == '-' || str[i] == '+')
            throw (ScalarConverter::InvalidSignals());
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
};

bool    ScalarConverter::isFloat(const std::string &str)
{
    int dot = 0, i = 0, n_count = 0;
    const int size = str.length();

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < size - 1)
    {
        if (str[i] == '-' || str[i] == '+')
            throw (ScalarConverter::InvalidSignals());
        else if (std::isdigit(str[i]))
            n_count++;
        else if (str[i] == '.')
            dot++;
        else
            throw(ScalarConverter::InvalidFloatNumber());
        i++;
    }
    if (dot == 0 || dot > 1)
        throw (ScalarConverter::MultipleDotsOrNone());
    if (n_count == 0)
        throw (ScalarConverter::InvalidFloatNumber());

    return true;
};

bool    ScalarConverter::isDouble(const std::string &str)
{
    const int size = str.length();
    int dot = 0, n_count = 0, i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < size)
    {
        if (str[i] == '-' || str[i] == '+')
            throw(ScalarConverter::InvalidSignals());
        else if (std::isdigit(str[i]))
            n_count++;
        else if (str[i] == '.')
            dot++;
        else
            throw (ScalarConverter::InvalidDoubleNumber());
        i++;
    }

    if (dot == 0 || dot > 1)
        throw (ScalarConverter::MultipleDotsOrNone());
    /* if (n_count == 0)
        throw (ScalarConverter::InvalidDoubleNumber()); */
    return true;
};

bool    ScalarConverter::isPseudoLiteral(const std::string &str)
{
    return (str == "nan" || str == "+inf" || str == "-inf" || 
            str == "nanf" || str == "+inff" || str == "-inff" ||
            str == "inf" || str == "inff");
};
// -------------------------------------------------------------
// --                                                         --
// --                       > End <                           --
// --                                                         --
// -------------------------------------------------------------

// -------------------------------------------------------------
// --                                                         --
// --                     > Convert <                         --
// --                                                         --
// -------------------------------------------------------------

void     ScalarConverter::convertChar(const std::string &str)
{
    char    c = str[0];

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
};

void    ScalarConverter::convertInt(const std::string &str)
{
    int     c = std::atoi(str.c_str());

    std::cout << std::fixed << std::setprecision(1);
    if (c >= 32 && c <= 126)
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    else if (c >= 0 && c <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;

    std::cout << "int: " << (c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
};

void    ScalarConverter::convertFloat(const std::string &str)
{
    float     c = std::atof(str.c_str());

    std::cout << std::fixed << std::setprecision(1);
    // Char
    if (c >= 32 && c <= 126)
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    else if (c >= 0 && c <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;

    //Int
    if (c >= std::numeric_limits<int>::min() && c <= std::numeric_limits<int>::max() && !std::isnan(c))
        std::cout << "int: " << static_cast<int>(c) << std::endl;
    else
        std::cout << "int: Impossible"<< std::endl;

    //Float
    if (c == static_cast<int>(c))
        std::cout << "float: " << c << "f" << std::endl;
    else
        std::cout << "float: " << c << "f" << std::endl;

    // Double
    if (c == static_cast<int>(c))
        std::cout << "double: " << c << std::endl;
    else
        std::cout << "double: " << c << std::endl;

};

void    ScalarConverter::convertDouble(const std::string &str)
{
    double   c = atof(str.c_str());

    std::cout << std::fixed << std::setprecision(1);
    // Char
    if (c >= 32 && c <= 126)
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    else if (c >= 0 && c <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;

    //Int
    if (c >= std::numeric_limits<int>::min() && c <= std::numeric_limits<int>::max() && !std::isnan(c))
        std::cout << "int: " << static_cast<int>(c) << std::endl;
    else
        std::cout << "int: Impossible"<< std::endl;

    //Float
    if (c >= std::numeric_limits<float>::min() && c <= std::numeric_limits<float>::max())
    {
        if (c == static_cast<int>(c))
            std::cout << "float: " << c << "f" << std::endl;
        else
            std::cout << "float: " << c << "f" << std::endl;
    }
    else
        std::cout << "float: Impossible" << std::endl;
    // Double
    if (c >= std::numeric_limits<double>::min() && c <= std::numeric_limits<double>::max())
    {
        if (c == static_cast<int>(c))
            std::cout << "double: " << c << std::endl;
        else 
            std::cout << "double: " << c << std::endl;
    }
    else
        std::cout << "double: Impossible" << std::endl;
};