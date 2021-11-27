#include "Fixed.hpp"

Fixed::Fixed ( void ) : _store(0) // Init list, assign zero to the FP value
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& from )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = from;
}

Fixed& Fixed::operator= (const Fixed& from)
{
	std::cout << "Assignation operator called" << std::endl;
	_store = from.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_store);
}

void	Fixed::setRawBits(const int bits)
{
	std::cout << "setRawBits member function called" << std::endl;
	_store = bits;
}