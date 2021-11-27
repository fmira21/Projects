#include "Dog.hpp"

Dog::Dog ( void )
{
    _type = "Dog";
    std::cout << BOLDYELLOW <<  "Default Dog constructor called" << DEFAULT << std::endl;
}

Dog::~Dog ( void )
{
    std::cout << BOLDYELLOW << "Dog destructor called" << DEFAULT << std::endl;
}

Dog::Dog ( const Dog& from )
{
	std::cout << BOLDYELLOW << "Dog copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

Dog& Dog::operator= (const Dog& from)
{
	std::cout << BOLDYELLOW << "Animal assignation operator called" << DEFAULT << std::endl;
    _type = from._type;

    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << BOLDYELLOW << "Bark! Bark! Awooooo!" << DEFAULT << std::endl;
}