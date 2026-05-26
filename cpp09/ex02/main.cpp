#include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    try
    {
        PmergeMe test;
        test.parsingInput(ac, av);
    }
    catch (std::exception &e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }

    return 0;
}