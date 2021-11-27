#include "Converter.hpp"

// Here, we can use C++ conversion functions or static cast.
// I've chosen the second one + standard functions to convert the string literals.

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BOLDRED << "Invalid number of arguments.\n" 
                  << BOLDYELLOW << "Example:\n"
                  << BOLDYELLOW << "./convert 42" << std::endl;
		return 1;
	}
	Converter conv(argv[1]);

std::cout << BOLDGREEN;

	conv.processChar();
	conv.processInt();
	conv.processFloat(); // Will use exponential notation in big numbers.
	conv.processDouble(); // Will use exponential notation in big numbers.

std::cout << DEFAULT;

	return 0;
}

// Nice reference:
// https://docs.microsoft.com/ru-ru/cpp/cpp/type-conversions-and-type-safety-modern-cpp?view=msvc-170