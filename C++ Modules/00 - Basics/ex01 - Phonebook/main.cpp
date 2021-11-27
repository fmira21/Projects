#include "Phonebook.hpp"

void initial_message(void)
{
	std::cout << BOLDBLUE << "Phonebook" << std::endl;
	std::cout << YELLOW << \
	"How to use:\n- ADD - add a new contact;\n- SEARCH - display existing contacts and find further data;\n- EXIT - quit the program." \
	<< DEFAULT << std::endl;
}

int main(void)
{
    std::string input;
    Phonebook PB;

	initial_message();
	PB.init_contacts(PB);
    while(!std::cin.eof())
	{
		std::cout << "[phonebook]> ";
		std::cin >> input;
		if (!input.compare("EXIT"))
			return 0;
		else if (!input.compare("ADD"))
			PB.add_contact(PB);
		else if (!input.compare("SEARCH"))
		{
			PB.search_message();
			PB.display_contacts(PB);
			PB.prompt_contact(PB);
		}
		else
			std::cout << "Invalid command\n";
	}
	return 0;
}