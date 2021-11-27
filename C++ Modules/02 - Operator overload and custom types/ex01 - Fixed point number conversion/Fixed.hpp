#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed ( void );
        ~Fixed ( void );
        Fixed ( const Fixed& from);
        Fixed ( const int from );               // Custom constructor for int -> FPv conversion
        Fixed ( const float from );             // Custom constructor for float -> FPv conversion
        Fixed& operator= (const Fixed& from);
        int getRawBits ( void ) const;
        void setRawBits ( const int bits );
        float toFloat ( void ) const;
        int toInt ( void ) const;
    private:
        int _store;
        static const int _frac_bits = 8;        //Q *.8
};

std::ostream &operator<< (std::ostream &to, const Fixed& from);

#endif