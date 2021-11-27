#ifndef _HUMANA_H_
#define _HUMANA_H_

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA( std::string name, Weapon &type );
	    ~HumanA( void );
        void attack( void );
    private:
        Weapon &_type;
        std::string _name;
};

#endif