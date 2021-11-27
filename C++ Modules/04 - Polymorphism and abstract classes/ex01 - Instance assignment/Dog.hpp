#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
    private:
        Brain* dogbrain;
    public:
        Dog ( void );
        ~Dog ( void );
        Dog ( const Dog& from); // Parametrised constructor for deep copy (see the cpp)
        Dog& operator= (const Dog& from);
        void makeSound() const;
};

#endif