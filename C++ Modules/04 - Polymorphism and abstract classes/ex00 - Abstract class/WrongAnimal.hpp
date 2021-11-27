#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "main.hpp"

class WrongAnimal 
{
    protected:
        std::string _type;
    public:
        WrongAnimal ( void );
        virtual ~WrongAnimal ( void );
        WrongAnimal ( const WrongAnimal& from);
        WrongAnimal& operator= (const WrongAnimal& from);
        virtual void makeSound(void) const; // The polymorphic function of the parent class should be virtual - it's behavior can be overriden in derived classes (https://en.cppreference.com/w/cpp/language/virtual).
        std::string getType( void ) const;
};

#endif