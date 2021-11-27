#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie chump(name);
    std::cout << BLUE << "Hey, " << name << ", say something!" << DEFAULT << std::endl;
    chump.announce();
}