#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed
{
    private:
        long long _value;
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
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
        
        Fixed   operator++(int);
        Fixed&   operator++(void);
        Fixed   operator--(int);
        Fixed&   operator--(void);

        static Fixed        &min(Fixed &a, Fixed &b);
        static Fixed        &max(Fixed &a, Fixed &b);
        static const Fixed  &min(const Fixed &a, const Fixed &b);
        static const Fixed  &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);