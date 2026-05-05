#include "Span.hpp"

int main(void)
{
    srand(time(0));
    try {
        Span    test(10);
        test.addNumber(4);
        test.addNumber(110);
        test.addNumber(88);
        test.addNumber(7);
        test.addNumber(66);
        test.addNumber(1);
        test.addNumber(44);
        test.addNumber(10);
        test.addNumber(99);
        test.addNumber(56);
        test.printSpan();
        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error : " << e.what() << std::endl;
    };

    try 
    {
        Span test2(4);
        test2.addMultipleNumbers(2);
        test2.printSpan();
    }
    catch (std::exception &e) {
        std::cout << "Error : " << e.what() << std::endl;
    };

    return (0);
}
