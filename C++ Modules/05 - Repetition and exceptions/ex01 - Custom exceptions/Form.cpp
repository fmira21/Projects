#include "Form.hpp"

const char* Form::gradeTooLowException::what() const throw()
{
    return ("Error: Too low grade to sign this form");
}

const char* Form::tooLowGradeToSignException::what() const throw()
{
    return ("Error: Form grade to sign cannot be lower than 150");
}

const char* Form::tooHighGradeToSignException::what() const throw()
{
    return ("Error: Form grade to sign cannot be higher than 1");
}

const char* Form::tooLowGradeToExecuteException::what() const throw()
{
    return ("Error: Form grade to execute cannot be lower than 150");
}

const char* Form::tooHighGradeToExecuteException::what() const throw()
{
    return ("Error: Form grade to execute cannot be higher than 1");
}

Form::Form(void) 
: _name("Default"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false)
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    checkFormGrades(_gradeToSign, _gradeToExecute);
// NB: Here we initialize the unsigned form by default.
}

Form::Form (const Form& from)
: _name(from._name), _gradeToSign(from._gradeToSign), _gradeToExecute(from._gradeToExecute), _isSigned(from._isSigned)
{
    *this = from;
}

Form::~Form(void)
{
}

Form& Form::operator=( const Form& from )
{
    if (this == &from)
        return (*this);
    _isSigned = from._isSigned;
    return (*this);
}

void Form::beSigned(Bureaucrat &signer)
{
    if (signer.getGrade() > _gradeToSign)
    {
        std::cout << BOLDRED << "Bureaucrat " << signer.getName() << " cannot sign this form, because ";
        throw Form::gradeTooLowException();
    }
    signer.signForm(*this);
}

std::string const &Form::getName() const
{
    return (_name);
}

const int &Form::getGradeToSign(void) const
{
    return(_gradeToSign);
}

const int &Form::getGradeToExecute(void) const
{
    return(_gradeToExecute);
}

void Form::checkFormGrades(int gradeToSign, int gradeToExecute ) const
{
    if ( gradeToSign < 1 )
        throw Form::tooHighGradeToSignException();
    if ( gradeToSign > 150 )
        throw Form::tooLowGradeToSignException();

    if ( gradeToExecute < 1 )
        throw Form::tooHighGradeToExecuteException();
    if ( gradeToExecute > 150 )
        throw Form::tooLowGradeToExecuteException();
}

const bool &Form::getIsSigned(void) const
{
    return (_isSigned);
}

void Form::setSignature(void)
{
    if (this->_isSigned == true)
        throw Bureaucrat::isSigned();
    _isSigned = true;
}

std::ostream&	operator<<( std::ostream& to, const Form& from )
{
	to << "Form name: " << from.getName() << std::endl;
	to << "Form grade to sign: " << from.getGradeToSign() << std::endl;
    to << "Form grade to execute: " << from.getGradeToExecute() << std::endl;
    to << "Form signing status: " << from.getIsSigned() << std::endl;

	return (to);
}