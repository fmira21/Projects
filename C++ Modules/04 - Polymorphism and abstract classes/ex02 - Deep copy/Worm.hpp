#ifndef WORM_HPP
#define WORM_HPP

// Class for deep copy testing. Direct cretion assigns brain, but shallow copy not.

#include "Animal.hpp"
#include "Brain.hpp"

class Worm : public Animal 
{
    private:
        Brain* wormbrain;
    protected:
        std::string _type;
    public:
        Worm ( void );
        virtual ~Worm ( void );
        Worm ( const Worm& from); // Conventional copy constructor
        Worm& operator= (const Worm& from);
        void makeSound(void) const;
        void getBrain(void) const;
};

#endif