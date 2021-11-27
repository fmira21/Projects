#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	nameless;
	ClapTrap	fmira("fmira");
	ClapTrap	clone(fmira);

	nameless.attack("Clap");
	clone.attack("Trap");
	fmira.attack("Enemy");
	fmira.takeDamage(2);
	fmira.takeDamage(9);
    fmira.attack("Friend");
	fmira.beRepaired(1);
	fmira.beRepaired(100);
	clone.attack("Clap");
	clone.attack("Trap");
	clone.attack("Anonymous");
	nameless.takeDamage(10);
	nameless.attack("fmira");
	

	return (0);
}