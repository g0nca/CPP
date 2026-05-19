#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw (BitcoinExchange::InvalidArguments());
        BitcoinExchange b;
        b.processInput(av[1]);

    }
    catch(const std::exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }
    return (0);
}