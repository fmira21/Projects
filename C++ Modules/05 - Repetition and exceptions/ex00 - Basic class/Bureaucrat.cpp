#include "Bureaucrat.hpp"

const char* Bureaucrat::gradeTooHighException::what() const throw()
{
    return ("Error: Too high grade");
}

const char* Bureaucrat::gradeTooLowException::what() const throw()
{
    return ("Error: Too low grade");
}

void Bureaucrat::checkGrade( int grade )
{
    if ( grade < 1 )
        throw Bureaucrat::gradeTooHighException();
    if ( grade > 150 )
        throw Bureaucrat::gradeTooLowException();
}

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(1)
{
    
}

Bureaucrat::Bureaucrat( const std::string name, int grade )
: _name(name), _grade(grade)
{
    checkGrade(_grade);
}

Bureaucrat::Bureaucrat (const Bureaucrat& from)
{
    *this = from;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& from )
{
    checkGrade(from._grade);
    _grade = from._grade;

    return (*this);
}

std::string const &Bureaucrat::getName() const
{	
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
	checkGrade( _grade - 1 );
    --_grade;
}
void Bureaucrat::decrementGrade()
{
	checkGrade( _grade + 1 );
	++_grade;
}

std::ostream&	operator<<( std::ostream& to, const Bureaucrat& from )
{
	to << "Bureaucrat name: " << from.getName() << std::endl;
	to << "Bureaucrat grade: " << from.getGrade() << std::endl;
	return (to);
}