#include "Fixed.hpp"

int main(void)
{
    Fixed a(3);
    Fixed b(2);

    std::cout << a << std::endl;
    std::cout << a / b << std::endl;
    return (0);
}