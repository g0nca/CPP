#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    FIxed J (1.5f);
    Fixed b ( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}