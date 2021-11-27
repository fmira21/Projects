#include "Fixed.hpp"

Fixed::Fixed ( void ) : _store(0)
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

// New constructors:

Fixed::Fixed(int const from) : _store(from << _frac_bits) // Init list: left-shift frac_bits in FROM and store
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(float const from) : _store(roundf(from * float(1 << _frac_bits))) // Init list: floated left-shift frac_bits in, multiply by FROM, find the nearest int and store
{
	std::cout << "Floating point constructor called" << std::endl;
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

// New functions:

float	Fixed::toFloat(void) const
{
	float out;

	out = (float)_store / float(1 << _frac_bits); // Divide the initialized STORE value by floated fractional bits assigned to 1 via the iverloaded << operator
	
	return (out); // Can pack the above into return, BTW.
}

int	Fixed::toInt(void) const
{
	int out;

	out = _store >> _frac_bits; // Assign the initialized STORE value to fractional bits.

	return (out);
}

// New overload operator:

std::ostream &operator<< (std::ostream &to, const Fixed& from)
{
	to << from.toFloat();
	return (to);
}
