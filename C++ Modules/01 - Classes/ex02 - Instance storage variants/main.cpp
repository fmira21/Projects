#include <iostream>
#include <string>

# define DEFAULT "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringptr = &brain; //Variable address -> Pointer (point to a variable). To operate the pointer, dereference it.
    std::string &stringref = brain; // Variable -> Reference (alias). You can operate the alias in the same way as the variable itself.

    std::cout << YELLOW;
    std::cout << "|    HOW    |      WHAT      |   WHERE   |" << std::endl;
    std::cout << "|     " << GREEN << "String" << YELLOW << "|" << RED << brain << YELLOW << "|" << RED << &brain << YELLOW << "|" << std::endl;
    std::cout << "|    " << GREEN << "Pointer" << YELLOW << "|" << RED << *stringptr << YELLOW << "|" << RED << stringptr << YELLOW << "|" << std::endl;
    std::cout << "|  " << GREEN << "Reference" << YELLOW << "|" << RED << stringref << YELLOW << "|" << RED << &stringref << YELLOW << "|" << std::endl;
}