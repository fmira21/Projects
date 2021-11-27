#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
    public:
        Dog ( void );
        ~Dog ( void );
        Dog ( const Dog& from);
        Dog& operator= (const Dog& from);
        void makeSound() const;
};

#endif