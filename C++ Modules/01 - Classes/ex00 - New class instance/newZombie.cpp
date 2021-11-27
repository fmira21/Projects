#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *zombieptr = new Zombie(name);
    return (zombieptr);
}