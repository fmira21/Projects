#include "Worm.hpp"

Worm::Worm ( void )
{
    _type = "Worm";
    wormbrain = new Brain();
    std::cout << BOLDRED <<  "Default Brain constructor called, brain is included" << DEFAULT << std::endl;
}

Worm::~Worm ( void )
{
    std::cout << BOLDRED << "Worm destructor called" << DEFAULT << std::endl;
    if (wormbrain)
        delete wormbrain;
}

Worm::Worm ( const Worm& from ) // Shallow copy constructor
{
	std::cout << BOLDRED << "Worm copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

Worm& Worm::operator= (const Worm& from)
{
	std::cout << BOLDWHITE << "Worm assignation operator called" << DEFAULT << std::endl;
    *wormbrain = *from.wormbrain; // Don't forget to copy the brain! It's outside the program frame, needs to be copied and destroyed separately!
    _type = from._type;

    return(*this);
}

void Worm::makeSound(void) const
{
    std::cout << BOLDRED << "Yo, are you kidding?" << DEFAULT << std::endl;
}

void Worm::getBrain(void) const
{
    if (this->wormbrain)
        std::cout << BOLDRED << "Brain exists." << DEFAULT << std::endl;
    else
        std::cout << BOLDRED << "No brain." << DEFAULT << std::endl;
}