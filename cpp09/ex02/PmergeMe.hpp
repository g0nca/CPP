#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <ctime>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <exception>

class Error : public std::exception
{
    private:
        std::string     _msg;
    public:
        Error(const std::string &msg) throw() : _msg(msg){};
        virtual ~Error() throw() {};
        virtual const char *what() const throw() { return _msg.c_str(); }
};

class PmergeMe
{
    private:
        std::deque<int>     _deque;
        std::vector<int>    _vector;
        double              _timeVector;
        double              _timeDeque;

        // ---------------- Vector Functions -------------
        void    sortVector();
        std::vector<std::pair<int, int> >   makePairsVector(const std::vector<int> &input, int &stranggler, bool &hasStranggler);
        std::vector<int>                    mergeInsertVector(std::vector<std::pair<int, int> > &pairs);
        std::vector<size_t>                 generateJacobsthalOrderVector(size_t n);
        void                                insertPendantVector(std::vector<int> &chain, int pendant, int anchor);

        // ---------------- Deque Functions --------------
        void                                sortDeque();
        std::deque<std::pair<int, int> >    makePairsDeque(const std::deque<int> &input, int &straggler, bool &hasStraggler);
        std::deque<int>                     mergeInsertDeque(std::deque<std::pair<int, int> > &pairs);
        std::deque<size_t>                  generateJacobsthalOrderDeque(size_t n);
        void                                insertPendantDeque(std::deque<int> &chain, int pendant, int anchor);

        size_t   jacobsthal(size_t n);
    public:
        PmergeMe();
        PmergeMe( const PmergeMe& );
        PmergeMe& operator=(const PmergeMe &);
        ~PmergeMe();

        void    printVector( void ) const ;
        void    printDeque( void ) const ;
        
        void    parsingInput(int ac, char **av);

        void    sort();
        void    printResults() const;

        static double getCurrentTimeMicro();
};

