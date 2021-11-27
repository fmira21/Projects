#include "WrongCat.hpp"

WrongCat::WrongCat ( void )
{
    _type = "WrongCat";
    std::cout << BOLDRED <<  "Default WrongCat constructor called" << DEFAULT << std::endl;
}

WrongCat::~WrongCat ( void )
{
    std::cout << BOLDRED << "WrongCat destructor called" << DEFAULT << std::endl;
}

WrongCat::WrongCat ( const WrongCat& from )
{
	std::cout << BOLDRED << "WrongCat copy constructor called" << DEFAULT << std::endl;
	*this = from;
}

WrongCat& WrongCat::operator= (const WrongCat& from)
{
	std::cout << BOLDRED << "WrongCat assignation operator called" << DEFAULT << std::endl;
    _type = from._type;

    return(*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << BOLDRED << "!wooeeM !woeM !woeM" << DEFAULT << std::endl;
}