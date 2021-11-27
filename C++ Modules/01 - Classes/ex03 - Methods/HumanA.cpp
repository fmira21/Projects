#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &type ) : _type(type), _name(name){}

HumanA::~HumanA(){}

void HumanA::attack( void )
{
    std::cout << GREEN << _name << YELLOW << " attacks with his " << RED << _type.getType() << DEFAULT << std::endl;
}