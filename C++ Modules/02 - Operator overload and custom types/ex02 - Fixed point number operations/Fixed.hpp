#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include <cmath>

# define DEFAULT "\033[0m"
# define BLACK   "\033[30m" 
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BOLDBLACK   "\033[1m\033[30m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDGREEN   "\033[1m\033[32m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN    "\033[1m\033[36m"
# define BOLDWHITE   "\033[1m\033[37m"

class Fixed {
    public:
        Fixed ( void );
        ~Fixed ( void );
        Fixed ( const Fixed& from);
        Fixed ( const int from );
        Fixed ( const float from );
        Fixed& operator= (const Fixed& from);
        // New binary operators:
        bool operator> (const Fixed& from) const;
        bool operator< (const Fixed& from) const;
        bool operator>= (const Fixed& from) const;
        bool operator<= (const Fixed& from) const;
        bool operator== (const Fixed& from) const;
        bool operator!= (const Fixed& from) const;
        // New arithmetic operators:
        Fixed operator+ (const Fixed& from) const;
        Fixed operator- (const Fixed& from) const;
        Fixed operator* (const Fixed& from) const;
        Fixed operator/ (const Fixed& from) const;
        // New pre-operators:
        Fixed operator++();
        Fixed operator--();
        // New post-operators:
        Fixed operator++(int);
        Fixed operator--(int);

        int getRawBits ( void ) const;
        void setRawBits ( const int bits );
        float toFloat ( void ) const;
        int toInt ( void ) const;

        // New functions:
        static Fixed& min (Fixed& f1, Fixed& f2);
        static const Fixed& min (const Fixed& f1, const Fixed& f2); // Function overload for const values
        static Fixed& max (Fixed& f1, Fixed& f2);
        static const Fixed& max (const Fixed& f1, const Fixed& f2); // Function overload for const values
    
    private:
        int _store;
        static const int _frac_bits = 8;        //Q *.8
};

std::ostream &operator<< (std::ostream &to, const Fixed& from);

#endif