#include <iostream>
#include <iomanip>
#include <string>

class Fixed
{
    private :
        int                 _value;
        static const int    _fac_bits = 8;

    public :
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw);
};