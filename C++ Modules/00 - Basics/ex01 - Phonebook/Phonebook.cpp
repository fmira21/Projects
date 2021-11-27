#include "Phonebook.hpp"

int is_book(int num)
{
	if (num >= 1 && num <= 8)
		return 1;
	else
		return 0;
}

bool is_present(Contact &contact)
{
	if (contact._first_name != "" && contact._last_name != "" && contact._nickname != "" && contact._phone_number != "" && contact._darkest_secret != "")
		return 1;
	return 0;
}

int ft_strlen(const std::string str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return i;
}

std::string display_entry(std::string str)
{
	if (ft_strlen(str) >= 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void Phonebook::init_contacts(Phonebook &PB)
{
	int i;

	for (i = 0; i <= 7; i++)
		PB._contacts[i]._old_one = 0;
}

void Phonebook::add_contact(Phonebook &PB)
{
	int i;
	int overflow_flag = 0;

	std::cin.ignore(10000, '\n');
	for (i = 0; i <= 7; i++)
	{
		if (PB._contacts[i]._old_one == 0)
		{
			std::cout << "First name: \n";
			getline(std::cin, PB._contacts[i]._first_name);
			std::cout << "Last name: \n";
			getline(std::cin, PB._contacts[i]._last_name);
			std::cout << "Nickname: \n";
			getline(std::cin, PB._contacts[i]._nickname);
			std::cout << "Phone number: \n";
			getline(std::cin, PB._contacts[i]._phone_number);
			std::cout << "Darkest secret: \n";
			getline(std::cin, PB._contacts[i]._darkest_secret);
			PB._contacts[i]._old_one = 1;
			overflow_flag = 1;
			break;
		}
	}
	if (overflow_flag == 0)
	{
		init_contacts(PB);
		add_contact(PB);
	}
}

void Phonebook::search_message(void)
{
	std::cout << YELLOW << \
	"Searching:\nEnter the contact index from the table below.\nIn case of invalid input, you will be returned to the main menu." \
	<< DEFAULT << std::endl;
}

void Phonebook::display_table_header(void)
{
	std::cout << std::setw(10) << "INDEX";
	std::cout << "|";
	std::cout << std::setw(10) << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << "NICKNAME";
	std::cout << "\n";
}

void Phonebook::display_contacts(Phonebook &PB)
{
	int i;

	PB.display_table_header();
	for (i = 0; i <= 7; i++)
	{
		if (is_present(PB._contacts[i]))
		{
			std::cout << std::setw(10) << i + 1;
			std::cout << "|";
			std::cout << std::setw(10) << display_entry(PB._contacts[i]._first_name);
			std::cout << "|";
			std::cout << std::setw(10) << display_entry(PB._contacts[i]._last_name);
			std::cout << "|";
			std::cout << std::setw(10) << display_entry(PB._contacts[i]._nickname);
			std::cout << "\n";
		}
	}
}

void Phonebook::display_details(Phonebook &PB, int index)
{
	if (is_present(PB._contacts[index]))
	{
		std::cout << "FIRST NAME: " << PB._contacts[index]._first_name << '\n';
		std::cout << "LAST NAME: "<< PB._contacts[index]._last_name << '\n';
		std::cout << "NICKNAME: "<< PB._contacts[index]._nickname << '\n';
		std::cout << "PHONE NUMBER: "<< PB._contacts[index]._phone_number << '\n';
		std::cout << "DARKEST SECRET: " << PB._contacts[index]._darkest_secret << '\n';
	}
	else
		std::cout << "No entry\n";
}

void Phonebook::prompt_contact(Phonebook &PB)
{
	int input;

	while (!std::cin.eof())
	{
		std::cout << "[phonebook/search]> ";
		std::cin >> input;
		if (input == '0')
			break ;
		else if (!(is_book(input)))
		{
			std::cout << "Invalid input\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		else
		{
			PB.display_details(PB, input - 1);
			break;
		}
	}
}