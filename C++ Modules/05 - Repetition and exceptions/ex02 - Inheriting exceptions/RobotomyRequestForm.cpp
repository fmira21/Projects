#include "RobotomyRequestForm.hpp"

const char *RobotomyRequestForm::robotomyFailureException::what() const throw()
{
	    return ("Error: Robotomy failed");
}

RobotomyRequestForm::RobotomyRequestForm(void) : Form ("Default RRF", 72, 45)
{
    _target = "Default RRF target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form ("RRF", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &from)
: Form(from._name, from._gradeToSign, from._gradeToExecute) 
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& from )
{
    if (this == &from)
        return (*this);
    _isSigned = from._isSigned;
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return(_target);
}

void RobotomyRequestForm::beExecuted(void) const
{
    srand(time(NULL)); // Assign the current time for the random generation seed.

    std::cout << BOLDMAGENTA << "*** Drilling noises... ***" << DEFAULT << std::endl;
    if (rand() % 2 == 0)
    {
        std::cout << BOLDRED << getTarget() << " has not been robotomized. Sad, but true." << std::endl;
        //throw robotomyFailureException(); // Can throw an exception, but for testing purposes just output.
    }
    else
        std::cout << BOLDMAGENTA << getTarget() << " has been robotomized. Congrats." << DEFAULT << std::endl;
}