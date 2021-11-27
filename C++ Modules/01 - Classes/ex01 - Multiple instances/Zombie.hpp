#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <iostream>
#include <string>

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

class Zombie {
    public:
        Zombie( std::string name );
        Zombie( void );
	    ~Zombie( void );
        void announce( void );
        void setName( std::string name );
    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif