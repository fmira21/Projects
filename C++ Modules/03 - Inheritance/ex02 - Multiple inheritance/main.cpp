#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main()
{
	std::cout << GREEN << "ClapTrap cases:" << std::endl;

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

	std::cout << std::endl << GREEN << "ScavTrap cases:" << std::endl;

	ScavTrap	sseleman;
	ScavTrap	arimf("arimf");
	ScavTrap	enolc(arimf);

	sseleman.attack("Clap");
	enolc.attack("Trap");
	arimf.attack("Enemy");
	arimf.takeDamage(2);
	arimf.takeDamage(9);
    arimf.attack("Friend");
	arimf.beRepaired(1);
	arimf.beRepaired(100);
	enolc.attack("Clap");
	enolc.attack("Trap");
	enolc.attack("Anonymous");
	sseleman.takeDamage(10);
	sseleman.attack("fmira");
	sseleman.guardGate();
	enolc.guardGate();
	arimf.guardGate();

	std::cout << std::endl << GREEN << "FragTrap cases:" << std::endl;

	FragTrap	vasily;
	FragTrap	petr("Petr");
	FragTrap	sasha(petr);

	vasily.attack("Clap");
	petr.attack("Trap");
	sasha.attack("Enemy");
	petr.takeDamage(2);
	petr.takeDamage(9);
    petr.attack("Friend");
	petr.beRepaired(1);
	petr.beRepaired(100);
	sasha.attack("Clap");
	sasha.attack("Trap");
	sasha.attack("Anonymous");
	vasily.takeDamage(10);
	vasily.attack("fmira");
	vasily.highFivesGuys();
	petr.highFivesGuys();
	sasha.highFivesGuys();

	return (0);
}