#include "Fixed.hpp"
/* 
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed();
        Fixed::Fixed(const Fixed &copy);
        Fixed   &operator=(const Fixed &copy);
        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const n); */
    
Fixed::Fixed(){
};

Fixed::Fixed(const Fixed &copy): _value(copy._value){
    std::cout << "Copy Constructor Called" << std::endl;
};

Fixed &Fixed::operator=(const Fixed &copy){
    std::cout << "Copy Assignment Called" << std::endl;
    if (this != &copy)
        this->_value = copy.getRawBits();
    return (*this);
};

Fixed::Fixed(const int n): _value(n << _bits){
    std::cout << "Int Constructor Called" << std::endl;
};

Fixed::Fixed(const float n): _value(roundf(n * (1 << _bits))) {
    std::cout << "Float Constructor Called" << std::endl;
};

Fixed::~Fixed(){
};




int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
};

void    Fixed::setRawBits(int const n) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = n;
};

int   Fixed::toInt(void) const {
    return (this->_value >> _bits);
};

float   Fixed::toFloat(void) const {
    return (this->_value / (1 << _bits));
};




std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return (out);
};




bool   Fixed::operator>(const Fixed &other) const {
    return (this->_value > other._value);
};

bool   Fixed::operator<(const Fixed &other) const {
    return (this->_value < other._value);
};

bool   Fixed::operator>=(const Fixed &other) const {
    return (this->_value >= other._value);
};

bool   Fixed::operator<=(const Fixed &other) const {
    return (this->_value <= other._value);
};

bool   Fixed::operator==(const Fixed &other) const {
    return (this->_value == other._value);
};

bool   Fixed::operator!=(const Fixed &other) const {
    return (this->_value != other._value);
};




Fixed   Fixed::operator+(const Fixed &other) const {
    Fixed temp;

    temp._value = this->_value + other._value;
    return (temp);
};

/* Fixed   Fixed::operator-(const Fixed &other) const {};
Fixed   Fixed::operator*(const Fixed &other) const {};
Fixed   Fixed::operator/(const Fixed &other) const {};
 */