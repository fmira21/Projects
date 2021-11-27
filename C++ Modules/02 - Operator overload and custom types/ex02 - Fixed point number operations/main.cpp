#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << BOLDRED << "Subject cases:" << DEFAULT << std::endl << std::endl;
    std::cout << MAGENTA <<  a << DEFAULT << std::endl;
    std::cout << MAGENTA << ++a << DEFAULT << std::endl;
    std::cout << MAGENTA << a << DEFAULT << std::endl;
    std::cout << MAGENTA << a++ << DEFAULT << std::endl;
    std::cout << MAGENTA << a << DEFAULT << std::endl;
    std::cout << MAGENTA << b << DEFAULT << std::endl;
    std::cout << MAGENTA << Fixed::max( a, b ) << DEFAULT << std::endl;
    
    std::cout << std::endl;
    std::cout << BOLDGREEN << "Self-cases:" << DEFAULT << std::endl;

	Fixed c  = Fixed(5.05f) + Fixed(2);
	Fixed d  = Fixed(5.05f) - Fixed(2);
    Fixed e  = Fixed (5.05f) / Fixed(2);

    std::cout << std::endl << GREEN << "Generate: " << DEFAULT << std::endl << std::endl;
    std::cout << MAGENTA << c << DEFAULT << std::endl;
    std::cout << MAGENTA << d << DEFAULT << std::endl;
    std::cout << MAGENTA << e << DEFAULT << std::endl << std::endl;

    std::cout << GREEN << "Compare: " << DEFAULT << std::endl << std::endl;

    std::cout << "Max: " << MAGENTA << Fixed::max(c, d) << DEFAULT << std::endl;
    std::cout << "Min: " << MAGENTA << Fixed::min(c, d) << DEFAULT << std::endl << std::endl;

    std::cout << GREEN << "Decrement: " << DEFAULT << std::endl << std::endl;
    std::cout << --c << DEFAULT << std::endl;
    std::cout << c-- << " --> " << c << DEFAULT << std::endl;
    
    return 0;
}