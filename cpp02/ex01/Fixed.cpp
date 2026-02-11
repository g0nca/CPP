/*
        Fixed   &operator=(const Fixed &copy);
        int     getRawBits(void) const;
        void    setRawBits(int const value);
*/
#include "Fixed.hpp"
/*
    Constructor & Destructors
    With fixed point inicializer
*/
Fixed::Fixed(): _value(0){
    std::cout << "Default Constructor" << std::endl;
};

Fixed::Fixed(const int value): _value(value << _bits){
    std::cout << "Int Constructor Called" << std::endl;
};

Fixed::Fixed(const float value): _value(round(value * (1 << _bits))){
    std::cout << "Float Constructor Called" << std::endl;
};

Fixed::~Fixed(){
};

/*
    Copy Objetcts
*/
Fixed &Fixed::operator=(const Fixed &copy){
    std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &copy)
        this->_value = copy.getRawBits();
    return (*this);
};

/*
    Getters & Setters
*/
int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
};

void    Fixed::setRawBits(int const value) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = value;
};
/*
    Conversion
*/
float   Fixed::toFloat(void) const {
    return (this->_value / (1 << _bits));
};

int     Fixed::toInt(void) const {
    return (this->_value >> _bits);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
};