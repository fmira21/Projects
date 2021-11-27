#ifndef _FRAGTRAP_H_
#define _FRAGTRAP_H_

class FragTrap : public ClapTrap
{
	public:
		FragTrap ( void );
        FragTrap ( std::string name );
        ~FragTrap ( void );
        FragTrap ( const FragTrap& from);
        FragTrap& operator= (const FragTrap& from);

		void highFivesGuys( void );
};

#endif