#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal ( void ) : _type("Animal")
{
    std::cout << BOLDBLUE <<  "Default WrongAnimal constructor called" << DEFAULT << std::endl;
}

WrongAnimal::~WrongAnimal ( void )
{
    std::cout << BOLDBLUE << "WrongAnimal destructor called" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal ( const WrongAnimal& from )
{
	std::cout << BOLDBLUE << "WrongAnimal copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& from)
{
	std::cout << BOLDBLUE << "WrongAnimal assignation operator called" << DEFAULT << std::endl;
    _type = from._type;

    return(*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << BOLDBLUE << ".tseT. tseT. tseT" << DEFAULT << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}