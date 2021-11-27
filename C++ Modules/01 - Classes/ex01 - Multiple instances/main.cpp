#include "Zombie.hpp"

int main(void)
{
    int hordeStrength = 5;
    int i = -1;
    Zombie *horde;

    std::cout << BLUE << "Rise and shine, my Horde!" << DEFAULT << std::endl;

    horde = zombieHorde(hordeStrength, "Jack");

    std::cout << BLUE << "I don't hear you roar!" << DEFAULT << std::endl;

    while (++i < hordeStrength)
        horde[i].announce();

    std::cout << BLUE << "That's better. Now die. Everyone." << DEFAULT << std::endl;

    delete[] horde;

    return 0;
}