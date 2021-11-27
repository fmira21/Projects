#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iomanip>
#include <map>

class Intern
{
    private:
        Form* shrubberyCreationForm(std::string formName);
        Form* robotomyRequestForm(std::string formName);
        Form* presidentialPardonForm(std::string formName);
        Form* throwInvalidFormNameException(std::string formName);

        struct formDictEntry {
            std::string 		name;
            Form* (Intern::*	makeFunction)( std::string formName );
	    };

	    static const formDictEntry formDict[];

    public:
        Intern (void);
        Intern (const Intern& from);
        ~Intern (void);

        Intern& operator=(const Intern &from);

        //Form makeForm(std::string formName, std::string target); // Omg, the Form class is abstract, have to go other way.

        Form* makeForm (std::string formName, std::string target);

        class invalidFormNameException : public std::exception
        {
            const char* what() const throw();
        };
};