#ifndef _SCAVTRAP_H_
#define _SCAVTRAP_H_

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap ( void );
        ScavTrap ( std::string name );
        ~ScavTrap ( void );
        ScavTrap ( const ScavTrap& from);
        ScavTrap& operator= (const ScavTrap& from);

		void guardGate( void );
};

#endif