#ifndef _HUMANB_H_
#define _HUMANB_H_

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB( std::string name );
	    ~HumanB( void );
        void setWeapon( Weapon &type ); // Since B does not acquire weapon in its constructor, we have to give him a weapon explicitly.
        void attack( void );
    private:
        Weapon *_type;
        std::string _name;
};

#endif