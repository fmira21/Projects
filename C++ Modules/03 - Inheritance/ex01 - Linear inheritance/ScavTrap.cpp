#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) // It is impossible to initialise the inherited class via an init list
{
	this->_name = "Anonymous_scav";
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_at_damage = 20;
    std::cout << BLUE << "Default constructor called.\nScavTrap " << this->_name << " created." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap ( std::string name )
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_at_damage = 20;
    std::cout << BLUE << "Custom constructor called.\nScavTrap " <<  this->_name << " created." << DEFAULT << std::endl;
}

ScavTrap::~ScavTrap ( void )
{
    std::cout << RED << "Destructor called.\nScavTrap " << this->_name << " is destroyed." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap& from )
{
	*this = from;
	this->_name = this->_name + "_clone";
	std::cout << BLUE << "Copy constructor called. ScavTrap " << this->_name << " is copied." << DEFAULT << std::endl;


}

ScavTrap &ScavTrap::operator=(const ScavTrap &from)
{
	_name = from._name;
	_energypoints = from._energypoints;
	_hitpoints = from._hitpoints;
	_at_damage = from._at_damage;

	return (*this);
}

void ScavTrap::guardGate( void )
{
	std::cout << BOLDWHITE << "ScavTrap " << this->_name << " has entered the Gate Keeper mode!" << std::endl;
}
