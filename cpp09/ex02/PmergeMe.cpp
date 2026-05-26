#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( const PmergeMe& copy )
{
    *this = copy;
}

PmergeMe&   PmergeMe::operator=( const PmergeMe& copy)
{
    if (this != &copy)
        *this = copy;
    return (*this);
}

PmergeMe::~PmergeMe(){}

void    PmergeMe::parsingInput( int ac, char **av )
{
    if (ac < 2)
        throw (Error("usage ./PmergeMe <positive numbers>"));

    for (int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);

        if (arg.empty())
            throw(Error("empty string"));
        if (arg[0] == '-' || arg[0] == '+')
            throw (Error("only positive numbers without sign"));
        for (size_t j = 0; j < arg.size(); j++)
            if (!std::isdigit(arg[j]))
                throw(Error("only numbers"));
        
        char *end;
        errno = 0;
        long val = strtol(arg.c_str(), &end, 10);
        if (*end != '\0' || errno == ERANGE)
            throw (Error("invalid number"));
        if (val <= 0)
            throw(Error("only positive numbers"));
        if (val > INT_MAX)
            throw (Error("number too large"));

        int n = static_cast<int>(val);


        std::cout << "N[" << i << "] : " << n << std::endl;
    }
}