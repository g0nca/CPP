#include "iter.hpp"

void    decrementValue(int  &value)
{
    value -= 1;
}

void    printValueFunction(const int &value)
{
    std::cout << value << " ";
}

void    printStringFunction(const std::string &str)
{
    std::cout << str << " ";
}

void    printFloatFunction(const float &value)
{
    std::cout << value << " ";
}

void    decrementFloatValue(float &value)
{
    value -= 1;
}

int     main(void)
{
    int     n_array[] = {0, 1, 2, 3, 4, 5};
    size_t  length = 6;

    std::cout << "---> Testing with instanciate templates <---" << std::endl;
    ::iter(n_array, length, printValue<int>);
    std::cout << std::endl;
    ::iter(n_array, length, incrementValue<int>);
    ::iter(n_array, length, printValue<int>);
    std::cout << std::endl << std::endl;


    std::cout << "---> Testing with Normal Functions (int) <---" << std::endl;
    ::iter(n_array, length, printValueFunction);
    ::iter(n_array, length, decrementValue);
    std::cout << std::endl;
    ::iter(n_array, length, printValueFunction);


    std::cout << std::endl << std::endl << "---> Testing with other type of data (std::string) <---" << std::endl;

    std::string     s_array[] = {"Hello", "World", "of", "42", "School"};
    size_t          s_length = 5;

    std::cout << "Using Template " << std::endl;
    ::iter(s_array, s_length, printValue<std::string>);
    std::cout << std::endl << "Using Function" << std::endl;
    ::iter(s_array, s_length, printStringFunction);

    std::cout << std::endl << std::endl << "---> Testing with other type of data (Float) <---" << std::endl;
    float   float_list[] = {2.4, 3.2, 5.6, 10.0};
    size_t  f_length = 4;

    std::cout << "Using Template " << std::endl;
    ::iter(float_list, f_length, printValue<float>);
    ::iter(float_list, f_length, incrementValue<float>);
    std::cout << std::endl;
    ::iter(float_list, f_length, printValue<float>);

    std::cout << std::endl << std::endl << "Using Function" << std::endl;
    ::iter(float_list, f_length, printFloatFunction);
    ::iter(float_list, f_length, decrementFloatValue);
    std::cout << std::endl;
    ::iter(float_list, f_length, printFloatFunction);
    return (0);
}