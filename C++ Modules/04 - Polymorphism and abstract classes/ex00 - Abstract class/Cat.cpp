#include "Cat.hpp"

Cat::Cat ( void )
{
    _type = "Cat";
    std::cout << BOLDWHITE <<  "Default Cat constructor called" << DEFAULT << std::endl;
}

Cat::~Cat ( void )
{
    std::cout << BOLDWHITE << "Cat destructor called" << DEFAULT << std::endl;
}

Cat::Cat ( const Cat& from )
{
	std::cout << BOLDWHITE << "Cat copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

Cat& Cat::operator= (const Cat& from)
{
	std::cout << BOLDWHITE << "Cat assignation operator called" << DEFAULT << std::endl;
    _type = from._type;

    return(*this);
}

void Cat::makeSound(void) const
{
    std::cout << BOLDWHITE << "Meow! Meow! Meeoow!" << DEFAULT << std::endl;
}