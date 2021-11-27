#include "Intern.hpp"

Intern::formDictEntry const Intern::formDict[] = {
	{"presidential pardon", &Intern::presidentialPardonForm},
	{"robotomy request", &Intern::robotomyRequestForm},
	{"shrubbery creation", &Intern::shrubberyCreationForm},
	{"other", &Intern::throwInvalidFormNameException}
};

Intern::Intern(void)
{
}

Intern::Intern (const Intern& from)
{
    *this = from;
}

Intern::~Intern(void)
{
}

Intern&	Intern::operator=( Intern const & )
{	
    return *this;
}

const char* Intern::invalidFormNameException::what() const throw()
{
    return ("Error: Invalid form name");
}

Form* Intern::presidentialPardonForm(std::string formName)
{
    Form* ppf = new PresidentialPardonForm(formName);
    return (ppf);
}

Form* Intern::robotomyRequestForm(std::string formName)
{
    Form* rrf = new RobotomyRequestForm(formName);
    return (rrf);
}

Form* Intern::shrubberyCreationForm(std::string formName)
{
    Form* scf = new ShrubberyCreationForm(formName);
    return (scf);
}

Form* Intern::throwInvalidFormNameException(std::string formName)
{
    (void)formName;
    throw Intern::invalidFormNameException();
}

Form* Intern::makeForm (std::string formName, std::string target)
{
    int dictSize = (sizeof(formDict) / sizeof(formDict[0])) - 1; // (Size of the entire dict in bytes / sizeof one entry) - 1 last byte
    int i = 0;
    while (i < dictSize && formName != formDict[i].name)
        i++;
    std::cout << BOLDYELLOW << "Intern has received a request for the form < " + formName + " >" << DEFAULT << std::endl;
    return((this->*formDict[i].makeFunction)(target));
}