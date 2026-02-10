#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
    return (*this);
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void    Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}