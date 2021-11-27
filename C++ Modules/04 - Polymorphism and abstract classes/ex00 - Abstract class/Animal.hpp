#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "main.hpp"

class Animal 
{
    protected:
        std::string _type;
    public:
        Animal ( void );
        virtual ~Animal ( void );
        Animal ( const Animal& from);
        Animal& operator= (const Animal& from);
        virtual void makeSound(void) const; // The polymorphic function of the parent class should be virtual - it's behavior can be overriden in derived classes (https://en.cppreference.com/w/cpp/language/virtual).
        std::string getType( void ) const;
};

#endif