#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( void )
{
/* Ex00 cases:
try
{
	// Valid cases:
	
	Bureaucrat bur1 ("bur1", 1);
	Bureaucrat bur150 ("bur150", 150);

	std::cout << BOLDGREEN
			  << bur1 	<< std::endl
			  << bur150 << std::endl
			  << DEFAULT << std::endl;

	bur1.incrementGrade();		// Will throw exception
	bur150.incrementGrade();	// Will work as intended

	std::cout << BOLDBLUE
			  << bur1 	<< std::endl
			  << bur150 << std::endl
			  << DEFAULT << std::endl;

	
	// Invalid cases:

	Bureaucrat bur0 ("bur0", 0);
	Bureaucrat bur151 ("bur151", 151);

	std::cout << BOLDGREEN
			  << bur0 	<< std::endl
			  << bur151 
			  << DEFAULT << std::endl;

	bur0.incrementGrade();
	bur151.incrementGrade();

	std::cout << BOLDBLUE
			  << bur0 	<< std::endl
			  << bur151 << std::endl
			  << DEFAULT << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << BOLDRED << e.what() << DEFAULT << std::endl;
}
*/

	try
	{
		Bureaucrat bur1 ("bur1", 1);
		std::cout << BOLDGREEN << bur1 << DEFAULT << std::endl;
		Bureaucrat bur40 ("bur40", 40);
		std::cout << BOLDGREEN << bur40 << DEFAULT << std::endl;
		Bureaucrat bur80 ("bur80", 80);
		std::cout << BOLDGREEN << bur80 << DEFAULT << std::endl;
		Bureaucrat bur150 ("bur150", 150);
		std::cout << BOLDGREEN << bur150 << DEFAULT << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm scf("toShrub");
		std::cout << BOLDWHITE << scf << DEFAULT;
		std::cout << BOLDYELLOW << "Target: " << scf.getTarget() << DEFAULT << std::endl;
		std::cout << std::endl;

		RobotomyRequestForm rrf("toRobo");
		std::cout << BOLDWHITE << rrf << DEFAULT;
		std::cout << BOLDYELLOW << "Target: " << rrf.getTarget() << DEFAULT << std::endl;
		std::cout << std::endl;

		PresidentialPardonForm ppf("toPardon");
		std::cout << BOLDWHITE << ppf << DEFAULT;
		std::cout << BOLDYELLOW << "Target: " << ppf.getTarget() << DEFAULT << std::endl;
		std::cout << std::endl;

// Better to comment out the cases, because otherwise the alreadySigned exception will be thrown.


		// Bur1 operations: Everything as expected

		scf.beSigned(bur1);
		scf.execute(bur1);

		std::cout << std::endl;

		rrf.beSigned(bur1);
		rrf.execute(bur1);

		std::cout << std::endl;

		ppf.beSigned(bur1);
		ppf.execute(bur1);

		// Bur40 operations:
/*
		scf.beSigned(bur40);
		scf.execute(bur40);

		std::cout << std::endl;

		rrf.beSigned(bur40);
		rrf.execute(bur40);

		std::cout << std::endl;

		ppf.beSigned(bur40); // Will throw a low grade exception here.
		ppf.execute(bur40);
*/
		// Bur80 operations:
/*
		scf.beSigned(bur80);
		scf.execute(bur80);

		std::cout << std::endl;

		rrf.beSigned(bur80); // Will throw a low grade exception here.
		rrf.execute(bur80);

		std::cout << std::endl;

		ppf.beSigned(bur80);
		ppf.execute(bur80);
*/
		// Bur150 operations:
/*
		scf.beSigned(bur150); // Will throw a low grade exception here
		scf.execute(bur150);

		std::cout << std::endl;

		rrf.beSigned(bur150);
		rrf.execute(bur150);

		std::cout << std::endl;

		ppf.beSigned(bur150);
		ppf.execute(bur150);
*/
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLDRED << e.what() << DEFAULT << std::endl;
	}
}