#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &from);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(const PresidentialPardonForm &source);

        std::string getTarget(void) const;
		void	beExecuted(void) const;
};