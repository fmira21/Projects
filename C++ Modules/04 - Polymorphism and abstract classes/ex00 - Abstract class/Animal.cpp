#include "Animal.hpp"

Animal::Animal ( void ) : _type("Animal")
{
    std::cout << BLUE <<  "Default Animal constructor called" << DEFAULT << std::endl;
}

Animal::~Animal ( void )
{
    std::cout << BLUE << "Animal destructor called" << DEFAULT << std::endl;
}

Animal::Animal ( const Animal& from )
{
	std::cout << BLUE << "Animal copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

Animal& Animal::operator= (const Animal& from)
{
	std::cout << BLUE << "Animal assignation operator called" << DEFAULT << std::endl;
    _type = from._type;

    return(*this);
}

void Animal::makeSound(void) const
{
    std::cout << BLUE << "Test. Test. Test." << DEFAULT << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}