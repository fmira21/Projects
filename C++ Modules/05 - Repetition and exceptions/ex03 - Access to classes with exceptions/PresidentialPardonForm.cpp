#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form ("Default PPF", 25, 5)
{
    _target = "Default PPF target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form ("PPF", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &from)
: Form(from._name, from._gradeToSign, from._gradeToExecute) 
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& from )
{
    if (this == &from)
        return (*this);
    _isSigned = from._isSigned;
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return(_target);
}

void PresidentialPardonForm::beExecuted(void) const
{
    std::cout << BOLDBLUE << getTarget() << " has been pardoned by Zafod Beeblebrox." << DEFAULT << std::endl;
}