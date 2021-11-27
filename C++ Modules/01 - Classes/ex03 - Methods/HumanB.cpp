#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name){}

HumanB::~HumanB( void ){}

void HumanB::setWeapon( Weapon &type )
{
    _type = &type;
}

void HumanB::attack( void )
{
    std::cout << GREEN << _name << YELLOW << " attacks with his " << RED << _type->getType() << DEFAULT << std::endl;
}