#include "ScalarConverter.hpp"

void test(const std::string &input)
{
    std::cout << "============================\n";
    std::cout << "Input: " << input << "\n";
    std::cout << "----------------------------\n";

    try
    {
        ScalarConverter::convert(input);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "============================\n\n";
}

int main()
{
    //CHAR
    test("a");
    test("Z");

    //INT
    test("0");
    test("42");
    test("-42");
    test("2147483647");
    test("-2147483648");

    //FLOAT
    test("0.0f");
    test("42.0f");
    test("-42.5f");
    test(".42f");
    test("42.f");

    //DOUBLE
    test("0.0");
    test("42.0");
    test("-42.5");
    test(".42");
    test("42.");

    //PSEUDO FLOAT
    test("nanf");
    test("+inff");
    test("-inff");

    //PSEUDO DOUBLE
    test("nan");
    test("+inf");
    test("-inf");

    //EDGE CASES
    test("999999999999999999999999"); // overflow
    test("abc");
    test("42abc");
    test("--42");
    test("..42");
    test("f42.0");

    return 0;
}
 
/* int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "./Conversion <number>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);

    return (0);
} */
 