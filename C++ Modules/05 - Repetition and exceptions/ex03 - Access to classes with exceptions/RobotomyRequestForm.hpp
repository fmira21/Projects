#pragma once

#include "Form.hpp"
#include <random>

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
    public:
        class robotomyFailureException : public std::exception
        {
			const char* what() const throw(); 
        };
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &from);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(const RobotomyRequestForm &source);

        std::string getTarget(void) const;
		void	beExecuted(void) const;
};