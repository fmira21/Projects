#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << BOLDGREEN << "<" << _name << "> " << YELLOW << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) // Constructor
{
    _name = name;
    announce();
}

Zombie::~Zombie(void) // Destructor
{
    std::cout << BOLDGREEN << _name << RED << " is dead. Finally, for this time." << DEFAULT << std::endl;
}