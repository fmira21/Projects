#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
    private:
        Brain* catbrain;
    public:
        Cat ( void );
        ~Cat ( void );
        Cat ( const Cat& from); // Parametrised constructor for deep copy (see the cpp)
        Cat& operator= (const Cat& from);
        void makeSound() const;
};

#endif