#include "whatever.hpp"

    int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

/* int main(void)
{
    int a = 0;
    int b = 4;

    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    swap(a, b);
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;

    std::cout << "Max between A & B : ";
    std::cout << max(a, b) << std::endl;

    std::cout << "Min between A & B : ";
    std::cout << min(a, b) << std::endl;

    return (0);
} */