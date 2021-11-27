#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) // It is impossible to initialise the inherited class via an init list
{
	this->_name = "Anonymous_frag";
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_at_damage = 30;
    std::cout << BLUE << "Default constructor called.\nFragTrap " << this->_name << " created." << DEFAULT << std::endl;
}

FragTrap::FragTrap ( std::string name )
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_at_damage = 30;
    std::cout << BLUE << "Custom constructor called.\nFragTrap " <<  this->_name << " created." << DEFAULT << std::endl;
}

FragTrap::~FragTrap ( void )
{
    std::cout << RED << "Destructor called.\nFragTrap " << this->_name << " is destroyed." << DEFAULT << std::endl;
}

FragTrap::FragTrap ( const FragTrap& from )
{
	*this = from;
	this->_name = this->_name + "_clone";
	std::cout << BLUE << "Copy constructor called. FragTrap " << this->_name << " is copied." << DEFAULT << std::endl;


}

FragTrap &FragTrap::operator=(const FragTrap &from)
{
	_name = from._name;
	_energypoints = from._energypoints;
	_hitpoints = from._hitpoints;
	_at_damage = from._at_damage;

	return (*this);
}

void FragTrap::highFivesGuys( void )
{
	std::cout << BOLDWHITE << "FragTrap: " << this->_name << ": High five, guys!" << std::endl;
}
