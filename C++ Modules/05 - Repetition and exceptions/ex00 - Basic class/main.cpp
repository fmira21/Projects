#include "Bureaucrat.hpp"

int main ( void )
{

try
{
	// Valid cases:
	Bureaucrat def;
	Bureaucrat bur1 ("bur1", 1);
	Bureaucrat bur150 ("bur150", 150);

	std::cout << BOLDGREEN
			  << def 	<< std::endl
			  << bur1 	<< std::endl
			  << bur150 << std::endl
			  << DEFAULT << std::endl;

	def.incrementGrade();		// Will throw exception 
	bur1.incrementGrade();		// Will throw exception
	bur150.incrementGrade();	// Will work as intended

	std::cout << BOLDBLUE
			  << bur1 	<< std::endl
			  << bur150 << std::endl
			  << DEFAULT << std::endl;

	
	// Invalid cases:
	/*
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
	*/
}
catch(const std::exception& e)
{
	std::cerr << BOLDRED << e.what() << DEFAULT << std::endl;
}


// Invalid case without try-catch: will result in an uncaught exception and abort the program. 
// Nevertheless, it will display out internal exception

/*
	Bureaucrat bur155( "bur155", 155 );
	std::cout << bur155 << std::endl; // Will never segfault, because we will end on the prev line.
*/
}