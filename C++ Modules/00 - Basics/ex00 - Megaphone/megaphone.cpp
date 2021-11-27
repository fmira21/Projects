#include <iostream>
#include <string>

void message(std::string message)
{
	std::cout << message;
}

std::string uppercase(std::string uppermes)
{
	int i;
	i = -1;
	while(uppermes[++i])
		uppermes[i] = std::toupper(uppermes[i]);
	return uppermes;
}

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		message("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
	else
	{
		i = 0;
		while(argv[++i])
			message(uppercase(argv[i]));
		std::cout << '\n';
	}
	return 0;
}