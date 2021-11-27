#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"

# define DEFAULT        "\033[0m"
# define BLACK          "\033[30m" 
# define RED            "\033[31m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define BLUE           "\033[34m"
# define MAGENTA        "\033[35m"
# define CYAN           "\033[36m"
# define WHITE          "\033[37m"
# define BOLDBLACK      "\033[1m\033[30m"
# define BOLDRED        "\033[1m\033[31m"
# define BOLDGREEN      "\033[1m\033[32m"
# define BOLDYELLOW     "\033[1m\033[33m"
# define BOLDBLUE       "\033[1m\033[34m"
# define BOLDMAGENTA    "\033[1m\033[35m"
# define BOLDCYAN       "\033[1m\033[36m"
# define BOLDWHITE      "\033[1m\033[37m"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        class gradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class gradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        class isSigned : public std::exception
        {
            const char* what() const throw();
        };

        Bureaucrat (void);
        Bureaucrat (const std::string name, int grade);
        Bureaucrat (const Bureaucrat& from);
        ~Bureaucrat (void);

        Bureaucrat& operator=(const Bureaucrat &from);

        std::string const &getName() const;
        int getGrade() const;

        void                checkGrade(int grade);
        void                incrementGrade(void);
        void                decrementGrade(void);
        void                signForm(Form &toSign);
        void                executeForm(Form const & form) const;
};

std::ostream& operator<<(std::ostream& to, const Bureaucrat& from);