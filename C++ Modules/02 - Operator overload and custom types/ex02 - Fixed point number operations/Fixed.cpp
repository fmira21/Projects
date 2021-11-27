#include "Fixed.hpp"

Fixed::Fixed ( void ) : _store(0)
{
    std::cout <<  "Default constructor called" << std::endl;
}

Fixed::~Fixed ( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& from )
{
	std::cout << DEFAULT << "Copy constructor called" << std::endl;
	*this = from;
}

Fixed& Fixed::operator= (const Fixed& from)
{
	std::cout << "Assignation operator called" << std::endl;
	_store = from.getRawBits();
	return (*this);
}

Fixed::Fixed(int const from) : _store(from << _frac_bits)
{
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(float const from) : _store(roundf(from * float(1 << _frac_bits)))
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

float	Fixed::toFloat(void) const
{
	float out;

	out = (float)_store / float(1 << _frac_bits);
	
	return (out);
}

int	Fixed::toInt(void) const
{
	int out;

	out = _store >> _frac_bits;

	return (out);
}

std::ostream &operator<< (std::ostream &to, const Fixed& from)
{
	to << from.toFloat();
	return (to);
}

// New binary operators:

bool Fixed::operator> (const Fixed& from) const
{
	bool out;

	out = this->toFloat() > from.toFloat();

	return (out);
}

bool Fixed::operator< (const Fixed& from) const
{
	bool out;

	out = this->toFloat() > from.toFloat();

	return (out);
}
        
bool Fixed::operator>= (const Fixed& from) const
{
	bool out;

	out = this->toFloat() >= from.toFloat();

	return (out);
}

bool Fixed::operator<= (const Fixed& from) const
{
	bool out;

	out = this->toFloat() <= from.toFloat();

	return (out);
}
        
bool Fixed::operator== (const Fixed& from) const
{
	bool out;

	out = this->toFloat() == from.toFloat();

	return (out);
}
        
bool Fixed::operator!= (const Fixed& from) const
{
	bool out;

	out = this->toFloat() != from.toFloat();

	return (out);
}

// New arithmetic operators:

Fixed Fixed::operator+ (const Fixed& from) const
{
	Fixed out;

	out = this->toFloat() + from.toFloat();

	return(out);
}

Fixed Fixed::operator- (const Fixed& from) const
{

	Fixed out;

	out = this->toFloat() - from.toFloat();

	return(out);

}

Fixed Fixed::operator* (const Fixed& from) const
{
	Fixed out;

	out = this->toFloat() * from.toFloat();

	return(out);
}

Fixed Fixed::operator/ (const Fixed& from) const
{
	Fixed out;

	out = this->toFloat() / from.toFloat();

	return(out);
}

// New pre-operators: Nothing challenging, just increment.
Fixed Fixed::operator++(void)
{
	this->_store = this->_store + 1;

	return(*this);
}

Fixed Fixed::operator--(void)
{
	this->_store = this->_store - 1;

	return(*this);
}

// New post-operators:

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++*this;
	return(temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--*this;
	return(temp);
}

// New functions:

Fixed& Fixed::min (Fixed& f1, Fixed& f2)
{
	return(f1.toFloat() < f2.toFloat() ? f1 : f2);
}

const Fixed& Fixed::min (const Fixed& f1, const Fixed& f2) // OL for const
{
	return(f1.toFloat() < f2.toFloat() ? f1 : f2);
}

Fixed& Fixed::max (Fixed& f1, Fixed& f2)
{
	return(f1.toFloat() > f2.toFloat() ? f1 : f2);
}

const Fixed& Fixed::max (const Fixed& f1, const Fixed& f2) // Function overload for const values
{
	return(f1.toFloat() > f2.toFloat() ? f1 : f2);
}
