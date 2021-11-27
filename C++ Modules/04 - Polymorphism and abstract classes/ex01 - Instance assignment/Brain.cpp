#include "Brain.hpp"

Brain::Brain ( void )
{
    std::cout << BOLDMAGENTA <<  "Default Brain constructor called" << DEFAULT << std::endl;
}

Brain::~Brain ( void )
{
    std::cout << BOLDMAGENTA << "Brain destructor called" << DEFAULT << std::endl;
}

Brain::Brain ( const Brain& from )
{
	std::cout << BOLDMAGENTA << "Brain copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

Brain& Brain::operator= (const Brain& from)
{
	std::cout << BOLDMAGENTA << "Brain assignation operator called" << DEFAULT << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = from._ideas[i];
    return(*this);
}