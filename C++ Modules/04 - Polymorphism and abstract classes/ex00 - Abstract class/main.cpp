#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
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

    std::cout << std::endl << BOLDMAGENTA << "WRONG classes:" << DEFAULT << std::endl << std::endl;

    std::cout << GREEN << "Creating WRONGANIMAL" << DEFAULT << std::endl;
        const WrongAnimal* wrongmeta = new WrongAnimal();
    std::cout << GREEN << "Copying WRONGANIMAL" << DEFAULT << std::endl;
        WrongAnimal wrongcopymeta(*wrongmeta);
    std::cout << GREEN << "Getting WRONGANIMAL type:" << DEFAULT << std::endl;
        std::cout << wrongmeta->getType() << " " << std::endl;
    std::cout << GREEN << "WRONGANIMAL sound" << DEFAULT << std::endl;
        wrongmeta->makeSound();
    
    std::cout << std::endl << GREEN << "Creating WRONGCAT" << DEFAULT << std::endl;
        const WrongAnimal* wrongi = new WrongCat();
    std::cout << GREEN << "Getting WRONGCAT type:" << DEFAULT << std::endl;
        std::cout << wrongi->getType() << " " << std::endl;
    std::cout << GREEN << "WRONGCAT sound" << DEFAULT << std::endl;
        wrongi->makeSound();

    std::cout << std::endl << GREEN << "Manual deletion of WRONG classes" << DEFAULT << std::endl;
        delete wrongmeta;
        delete wrongi;
    std::cout << std::endl << GREEN << "And now, the copied class instances:" << DEFAULT << std::endl;

}