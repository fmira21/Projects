#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _isSigned;
    
    public:
        class gradeTooLowException : public std::exception
        {
			const char* what() const throw(); 
        };

        class tooLowGradeToSignException : public std::exception
        {
			const char* what() const throw(); 
        };

        class tooHighGradeToSignException : public std::exception
        {
			const char* what() const throw(); 
        };

        class tooLowGradeToExecuteException : public std::exception
        {
			const char* what() const throw(); 
        };

        class tooHighGradeToExecuteException : public std::exception
        {
			const char* what() const throw(); 
        };

        Form (void);
        Form (const std::string name, const int gradeToSign, const int gradeToExecute);
        Form (const Form& from);
        ~Form ();

        Form& operator=(const Form &from);

        void beSigned(Bureaucrat &signer);

        std::string const &getName() const;
        const int &getGradeToSign(void) const;
        const int &getGradeToExecute(void) const;
        void checkFormGrades(int gradeToSign, int gradeToExecute) const;
        const bool &getIsSigned(void) const;
        void setSignature(void);

};

std::ostream& operator<<(std::ostream& to, const Form& from);