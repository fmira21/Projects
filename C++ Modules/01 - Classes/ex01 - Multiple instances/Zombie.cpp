#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << BOLDGREEN << "<" << _name << "> " << YELLOW << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::Zombie() // Default constructor: name and announcement are executed explicitly.
{
}

Zombie::Zombie(std::string name) // Non-default constructor
{
    _name = name;
    announce();
}

Zombie::~Zombie(void) // Destructor
{
    std::cout << BOLDGREEN << _name << RED << " is dead. Finally, for this time." << DEFAULT << std::endl;
}