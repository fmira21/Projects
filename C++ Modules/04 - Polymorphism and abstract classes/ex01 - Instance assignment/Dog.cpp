#include "Dog.hpp"

Dog::Dog ( void )
{
    _type = "Dog";
    dogbrain = new Brain();
    std::cout << BOLDYELLOW <<  "Default Dog constructor called, brain is included" << DEFAULT << std::endl;
}

Dog::~Dog ( void )
{
    std::cout << BOLDYELLOW << "Dog destructor called" << DEFAULT << std::endl;
    if (dogbrain)
        delete dogbrain;
}

Dog::Dog ( const Dog& from )// Parametrised constructor for deep copy
{
	std::cout << BOLDYELLOW << "Dog deep copy constructor called" << DEFAULT << std::endl;
	if (from.dogbrain)
        dogbrain = new Brain(*from.dogbrain);// Create the copied brain
    _type = from._type;
}

Dog& Dog::operator= (const Dog& from) 
{
	std::cout << BOLDYELLOW << "Animal assignation operator called" << DEFAULT << std::endl;
    *dogbrain = *from.dogbrain; // Don't forget to copy the brain! It's outside the program frame, needs to be copied and destroyed separately!
    _type = from._type;

    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << BOLDYELLOW << "Bark! Bark! Awooooo!" << DEFAULT << std::endl;
}