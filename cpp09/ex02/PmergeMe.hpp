#pragma once

#include <exception>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;

    public:
        PmergeMe();
        PmergeMe( const PmergeMe& );
        PmergeMe& operator=(const PmergeMe &);
        ~PmergeMe();

        void    parsingInput(int ac, char **av);
};

class Error : public std::exception
{
    private:
        std::string     _msg;
    public:
        Error(const std::string &msg) throw() : _msg(msg){};
        virtual ~Error() throw() {};
        virtual const char *what() const throw() { return _msg.c_str(); }
};