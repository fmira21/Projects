#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "main.hpp"

class Brain 
{
    protected:
        std::string _ideas [100];
    public:
        Brain ( void );
        virtual ~Brain ( void );
        Brain ( const Brain& from);
        Brain& operator= (const Brain& from);
};

#endif