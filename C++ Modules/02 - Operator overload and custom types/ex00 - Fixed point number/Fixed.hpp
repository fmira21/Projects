#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

class Fixed {
    public:
        Fixed ( void );                              // Default constructor
        ~Fixed ( void );                             // Default destructor
        Fixed ( const Fixed& from);                  // Copy (non-template) constructor
        Fixed& operator= (const Fixed& from);        // Overload operator: Reference to the operator as a member if this class with changing of its functions. We need it to remove some builtin restrictions, as well as to assign our own ones.
        int getRawBits ( void ) const;
        void setRawBits ( const int bits );
    private:
        int _store;                                  // Here we store the FP value
        static const int _frac_bits = 8;
};

#endif