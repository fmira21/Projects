#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
    public:
        WrongCat ( void );
        ~WrongCat ( void );
        WrongCat ( const WrongCat& from);
        WrongCat& operator= (const WrongCat& from);
        void makeSound() const;
};

#endif