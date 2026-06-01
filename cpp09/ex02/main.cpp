#include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    try
    {
        PmergeMe test;
        test.parsingInput(ac, av);
        std::cout << "Before -> "; 
        test.printVector();
        std::cout << std::endl;
        std::cout << "Before -> "; 
        test.printDeque();
        test.sort();
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "After -> ";
        test.printVector();
        std::cout << std::endl;
        std::cout << "After -> ";
        test.printDeque();
        std::cout << std::endl;
        test.printResults();
    }
    catch (std::exception &e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }

    return 0;
}