#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : Form ("Default SCF", 145, 137)
{
    _target = "Default SCF target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form ("SCF", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &from)
: Form(from._name, from._gradeToSign, from._gradeToExecute) 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& from )
{
    if (this == &from)
        return (*this);
    _isSigned = from._isSigned;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return(_target);
}

void ShrubberyCreationForm::beExecuted(void) const
{
    std::ofstream outfile;
    std::string filename = getTarget() + "_shrubbery";
    outfile.open(filename);
    outfile << "                      ___\n"
            << "                _,-'\"\"   \"\"\"\"`--.\n"
            << "             ,-'          __,,-- \n"
            << "           ,'    __,--\"\"\"\"dF      )\n"
            << "          /   .-\"Hb_,--\"\"dF      /\n"
            << "        ,'       _Hb ___dF\"-._,-'\n"
            << "      ,'      _,-\"\"\"\"   \"\"--..__\n"
            << "     (     ,-'                  `.\n"
            << "      `._,'     _   _             ;\n"
            << "       ,'     ,' `-'Hb-.___..._,-'\n"
            << "       \\    ,'\"Hb.-'HH`-.dHF\"\n"
            << "        \\'   \"Hb  HH  dF\"\n"
            << "                \"Hb HH dF\n"
            << "                 \"HbHHdF\n"
            << "                  |HHHF\n"
            << "                  |HHH|\n"
            << "                  |HHH|\n"
            << "                  |HHH|\n"
            << "                  |HHH|\n"
            << "                  dHHHb\n"
            << "                .dFd|bHb.               o\n"
            << "      o       .dHFdH|HbTHb.          o /\n"
            << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.       Y\n"
            << "##########################################\n"
            << std::endl;

    outfile.close();
    std::cout << BOLDGREEN << getTarget() << " has created the shrubbery <" << filename << ">" << std::endl;
}