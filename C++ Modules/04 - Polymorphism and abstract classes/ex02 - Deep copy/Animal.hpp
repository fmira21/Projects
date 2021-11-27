#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "main.hpp"

/*
This class is abstract.
It means, that no objects of ANIMAL can be created  and no non-static data members of an abstract class can be declared.
Abstract types cannot be used as parameter types, as function return types, or as the type of an explicit conversion.
*/

class Animal 
{
    protected:
        std::string _type;
    public:
        Animal ( void );
        virtual ~Animal ( void );
        Animal ( const Animal& from);
        Animal& operator= (const Animal& from);
        virtual void makeSound(void) const = 0; // The polymorphic function of the parent class should be virtual - it's behavior can be overriden in derived classes (https://en.cppreference.com/w/cpp/language/virtual).
        // Now, the class contains a pure virtual function makeSound which can be overriden by child classes.
        std::string getType( void ) const;
};

#endif