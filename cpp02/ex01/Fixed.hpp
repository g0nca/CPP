#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed
{
    private:
        const int _value;
        static const int _frac_int = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        float   toFloat(void) const;
        int     toInt(void) const;



};