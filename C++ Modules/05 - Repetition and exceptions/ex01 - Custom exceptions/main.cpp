#include "Bureaucrat.hpp"

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
		Bureaucrat bur22 ("bur22", 22);
		std::cout << BOLDGREEN << bur22 << DEFAULT << std::endl;
		Bureaucrat bur40 ("bur40", 40);
		std::cout << BOLDGREEN << bur40 << DEFAULT << std::endl;
		Form for25 ("for25", 25, 14);
		std::cout << BOLDMAGENTA << for25 << DEFAULT << std::endl;

		/*
		// Invalid forms:
		Form for100500("for100500", 100500, 100500);
		std::cout << BOLDMAGENTA << for100500 << DEFAULT << std::endl;

		Form for0("for0", 0, 0);
		std::cout << BOLDMAGENTA << for0 << DEFAULT << std::endl;
		*/

		// Valid signature:
		for25.beSigned(bur22);
		std::cout << BOLDMAGENTA << for25 << DEFAULT << std::endl;

		// Invalid signature:
		for25.beSigned(bur40);

		// Double signature:
		for25.beSigned(bur22);
		std::cout << BOLDMAGENTA << for25 << DEFAULT << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}