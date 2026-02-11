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
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed   &operator=(const Fixed &copy);
        int     getRawBits(void) const;
        void    setRawBits(int const value);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);