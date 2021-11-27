#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Anonymous_clap"), _hitpoints(0), _energypoints(0), _at_damage(0)
{
    std::cout << BLUE <<  "Default constructor called.\nClapTrap " << this->_name << " created." << DEFAULT << std::endl;
}

ClapTrap::ClapTrap ( std::string name ) : _name(name), _hitpoints(10), _energypoints(10), _at_damage(0)
{
    std::cout << BLUE << "Custom constructor called.\nClapTrap " <<  this->_name << " created." << DEFAULT << std::endl;
}

ClapTrap::~ClapTrap ( void )
{
    std::cout << RED << "Destructor called.\nClapTrap " << this->_name << " is destroyed." << DEFAULT << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap& from )
{
	*this = from;
	this->_name = this->_name + "_clone";
	std::cout << BLUE << "Copy constructor called. ClapTrap " << this->_name << " is copied." << DEFAULT << std::endl;


}

ClapTrap &ClapTrap::operator=(const ClapTrap &from)
{
	_name = from._name;
	_energypoints = from._energypoints;
	_hitpoints = from._hitpoints;
	_at_damage = from._at_damage;

	return (*this);
}


void ClapTrap::attack( std::string const &target )
{
	if (this->_hitpoints <= 0)
	{
		std::cout << BOLDRED << "ClapTrap " << this->_name << " cannot attack: not enough hitpoints(" << this->_hitpoints << "), needs reparation." << DEFAULT << std::endl;
		return ;
	}
	if (this->_energypoints > this->_at_damage)
	{
		this->_energypoints = this->_energypoints - this->_at_damage;
		std::cout << BOLDRED << "ClapTrap " << this->_name << " attack " << target << " causing " << this->_at_damage << " points of damage!" << std::endl;
		std::cout << "Energy left: " << this->_energypoints << DEFAULT << std::endl;
	}
	else
		std::cout << BOLDRED << "ClapTrap " << this->_name << " does not have enough energy points to attack." << BOLDRED << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > (int)amount)
	{
		this->_hitpoints = this->_hitpoints - amount;
		std::cout << MAGENTA << "ClapTrap " << this->_name << " has taken " << amount << " damage." << std::endl;
		std::cout << "Hitpoints left: " << this->_hitpoints << DEFAULT << std::endl;
	}
	else
	{
		this->_hitpoints = this->_hitpoints - amount;
		std::cout << MAGENTA << "ClapTrap " << this->_name << " has taken " << amount << " damage." << std::endl;
		std::cout << this->_name << " is broken. It cannot attack anymore.\nHitpoints: " << this->_hitpoints << DEFAULT << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitpoints = this->_hitpoints + (int)amount;
	std::cout << BOLDBLUE << "ClapTrap " << _name << " restores " << amount << " hitpoints.\nHitpoints available: " << _hitpoints << DEFAULT << "\n"; 
}