#include "Cat.hpp"

Cat::Cat ( void )
{
    _type = "Cat";
    catbrain = new Brain();
    std::cout << BOLDWHITE <<  "Default Cat constructor called, brain is included" << DEFAULT << std::endl;
}

Cat::~Cat ( void )
{
    std::cout << BOLDWHITE << "Cat destructor called" << DEFAULT << std::endl;
    if (catbrain)
        delete catbrain;
}

Cat::Cat ( const Cat& from ) // Parametrised constructor for deep copy
{
	std::cout << BOLDWHITE << "Cat deep copy constructor called" << DEFAULT << std::endl;
	if (from.catbrain)
        catbrain = new Brain(*from.catbrain);// Create the copied brain
    _type = from._type;
}

Cat& Cat::operator= (const Cat& from)
{
	std::cout << BOLDWHITE << "Cat assignation operator called" << DEFAULT << std::endl;
    *catbrain = *from.catbrain; // Don't forget to copy the brain! It's outside the program frame, needs to be copied and destroyed separately!
    _type = from._type;

    return(*this);
}

void Cat::makeSound(void) const
{
    std::cout << BOLDWHITE << "Meow! Meow! Meeoow!" << DEFAULT << std::endl;
}