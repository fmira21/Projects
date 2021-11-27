#include "Dog.hpp"
#include "Cat.hpp"
#include "Worm.hpp"

int main()
{
    std::cout << std::endl << GREEN << "Previous cases:" << DEFAULT << std::endl << std::endl;
    std::cout << GREEN << "Creating ANIMAL" << DEFAULT << std::endl;
        const Animal* meta = new Animal();
    std::cout << GREEN << "Copying ANIMAL" << DEFAULT << std::endl;
        Animal copymeta(*meta);
    std::cout << GREEN << "Getting ANIMAL type:" << DEFAULT << std::endl;
        std::cout << meta->getType() << " " << std::endl;
    std::cout << GREEN << "ANIMAL sound" << DEFAULT << std::endl;
        meta->makeSound();
    
    std::cout << std::endl << GREEN << "Creating DOG" << DEFAULT << std::endl;
        const Animal* j = new Dog();
    std::cout << GREEN << "Getting DOG type:" << DEFAULT << std::endl;
        std::cout << j->getType() << " " << std::endl;
    std::cout << GREEN << "DOG sound" << DEFAULT << std::endl;
        j->makeSound();

    std::cout << std::endl << GREEN << "Creating CAT" << DEFAULT << std::endl;
        const Animal* i = new Cat();
    std::cout << GREEN << "Getting CAT type:" << DEFAULT << std::endl;
        std::cout << i->getType() << " " << std::endl;
    std::cout << GREEN << "CAT sound" << DEFAULT << std::endl;
        i->makeSound();

    std::cout << std::endl << GREEN << "Manual deletion of ANIMAL classes" << DEFAULT << std::endl;
        delete meta;
        delete j;
        delete i;

    std::cout << std::endl << BOLDGREEN << "EX01 cases:" << DEFAULT << std::endl << std::endl;
    std::cout << std::endl << GREEN << "Creating animals array:" << DEFAULT << std::endl;
        const Animal* ar[5]; // Clang feature: [-Warray-bounds]: there can be an issue when the last element of aray may cause stack overflow when accessing it. GCC allows to do it, BTW.

        for (int i = 0; i < 5; i++)
        {
            if (i % 2)
            {
                ar[i] = new Dog();
                std::cout << ar[i]->getType() << " " << std::endl;
                ar[i]->makeSound();
            }
            else
            {
                ar[i] = new Cat();
                std::cout << ar[i]->getType() << " " << std::endl;
                ar[i]->makeSound();
            }
        }

    std::cout << std::endl << GREEN << "Deleting animals array manually:" << DEFAULT << std::endl;
        for (int i = 4; i >= 0; i--)
        {
            if (i % 2)
                delete ar[i];
            else
                delete ar[i];
        }

    std::cout << std::endl << GREEN << "Creating and deep copying:" << DEFAULT << std::endl;
        const Dog* a = new Dog();
        const Dog* b = new Dog(*a);
    std::cout << std::endl << GREEN << "Removing created and deep-copied instances:" << DEFAULT << std::endl;
        delete b;
        delete a;

    /*  Let's break the program with a shallow copy. */
    /*
    std::cout << std::endl << GREEN << "Creating worm:" << DEFAULT << std::endl;
        const Worm* w = new Worm();
    std::cout << std::endl << GREEN << "Shallow copying worm:" << DEFAULT << std::endl;
        const Worm* wc = new Worm(*w); // Here we can see that shallow copy doesn't work, because the brain is copied to nowhere (brain assignation operator will not work this out). This action will result a segfault. Otherwise, we have to overload a brain assignation operator and openly create a brainless worm. 
    */
    std::cout << std::endl << GREEN << "Call of default destructors:" << DEFAULT << std::endl;
}