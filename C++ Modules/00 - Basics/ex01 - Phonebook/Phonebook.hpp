#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Contact.hpp"

class Phonebook {
	public:
		int ft_strlen(const std::string str);
		void init_contacts(Phonebook &PB);
		void add_contact(Phonebook &PB);
		void search_message(void);
		void display_contacts(Phonebook &PB);
		void display_table_header(void);
		void display_details(Phonebook &PB, int index);
		void prompt_contact(Phonebook &PB);
	private:
		Contact _contacts[8];
};

#endif