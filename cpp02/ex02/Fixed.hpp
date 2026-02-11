#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &copy);
        ~Fixed();

        Fixed    &operator=(const Fixed &copy);

        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const n);
    
        bool   operator>(const Fixed &other) const;
        bool   operator<(const Fixed &other) const;
        bool   operator>=(const Fixed &other) const;
        bool   operator<=(const Fixed &other) const;
        bool   operator==(const Fixed &other) const;
        bool   operator!=(const Fixed &other) const;

        Fixed   operator+(const Fixed &other) const;

        /* Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const; */
        

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);