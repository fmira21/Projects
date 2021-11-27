#include "Zombie.hpp"

int main(void)
{
    std::cout << BLUE << "Rise and shine!" << DEFAULT << std::endl;
    
    Zombie karl("Karl"); // This one is on the stack.
    Zombie *Greg = newZombie("Greg"); // This one is on the heap.
    randomChump("Mark"); // This one is on the stack as a part of the function. I.e., it will be destroyed when the function calling it is executed.

    std::cout << BLUE << "And now, together!" << DEFAULT << std::endl;

    karl.announce();
    Greg->announce();

    std::cout << BLUE << "Oh, Mark is already dead. Poor guy, he realised he's not needed anymore. You two can also die." << DEFAULT << std::endl;

    delete(Greg);

    return 0;
}