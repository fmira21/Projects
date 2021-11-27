#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal 
{
    public:
        Cat ( void );
        ~Cat ( void );
        Cat ( const Cat& from);
        Cat& operator= (const Cat& from);
        void makeSound() const;
};

#endif