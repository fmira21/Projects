#pragma once 

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

#include <iostream>
#include <exception>

class notFoundException : public std::exception
{
    const char* what() const throw()
    {
        return "Not found :(";
    }
};

template <typename T>
void easyfind (const T& templ, const int num)
{
    if (std::find(templ.begin(), templ.end(), num) != templ.end())
        std::cout << BOLDGREEN << "Here it is: " << BOLDMAGENTA << num << DEFAULT << std::endl;
    else throw notFoundException();
};