#ifndef _CLAPTRAP_H_
#define _CLAPTRAP_H_

#include <iostream>

# define DEFAULT "\033[0m"
# define BLACK   "\033[30m" 
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define BOLDBLACK   "\033[1m\033[30m"
# define BOLDRED     "\033[1m\033[31m"
# define BOLDGREEN   "\033[1m\033[32m"
# define BOLDYELLOW  "\033[1m\033[33m"
# define BOLDBLUE    "\033[1m\033[34m"
# define BOLDMAGENTA "\033[1m\033[35m"
# define BOLDCYAN    "\033[1m\033[36m"
# define BOLDWHITE   "\033[1m\033[37m"

class ClapTrap {
    protected:
        std::string _name;
        int         _hitpoints;
        int         _energypoints;
        int         _at_damage;
    public:
        ClapTrap ( void );
        ClapTrap ( std::string name );
        ~ClapTrap ( void );
        ClapTrap ( const ClapTrap& from);
        ClapTrap& operator= (const ClapTrap& from);

        void        attack(std::string const &target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        destroyClap( void );
};

#endif