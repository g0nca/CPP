#include "Span.hpp"

Span::Span(): _n(0) {};

Span::Span(unsigned int number):_n(number) {};

Span::Span(const Span &copy)
{ 
    *this = copy;
};

Span    &Span::operator=(const Span &copy)
{
    if (this != &copy)
        this->_n = copy._n;
    return (*this);
};

Span::~Span(){};

void Span::printSpan() const {
    std::cout << "Span Content : ";
    for (unsigned int i = 0; i < this->_list.size(); i++) {
        std::cout << this->_list[i] << " ";
    }
    std::cout << std::endl;
}

void    Span::addMultipleNumbers(int n)
{
    if (n < 2)
        throw (Span::NotEnoughNumbers());
    this->_n = (unsigned int)n;
    for (unsigned int i = 0; i < (unsigned int)n; i++)
	{
		int randomNumber = rand() % 10000;
        this->_list.push_back(randomNumber);
	}
};


void    Span::addNumber(int n)
{
    if (this->_list.size() >= this->_n)
        throw (Span::MaxValueReached());
    _list.push_back(n);
};

int     Span::shortestSpan() 
{
    if (_list.size() <= 1)
        throw (Span::NotEnoughNumbers());
    
    std::vector<int> sorted = _list;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
        {
            minSpan = span;
        }
    }
    return (minSpan);
};

int     Span::longestSpan() 
{
    if (_list.size() <= 1)
        throw (Span::NotEnoughNumbers());

    std::vector<int> sorted = _list;
    std::sort(sorted.begin(), sorted.end());
    return (sorted.back() - sorted.front());
};
