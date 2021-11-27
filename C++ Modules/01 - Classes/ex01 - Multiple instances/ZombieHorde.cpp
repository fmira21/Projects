#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (!N)
        return(nullptr);

    int i = -1;
    Zombie* horde = new Zombie[N];

    

    while(++i < N)
    {
        char num = i + '0';
        horde[i].setName(name + " " + num);
        horde[i].announce();
    }

    return (horde);
}