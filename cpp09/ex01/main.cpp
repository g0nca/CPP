#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw (Error("Wrong number of arguments"));
        RPN b;
        int result = b.evaluate(av[1]);
        std::cout << result << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}