#pragma once

#include <iostream>
#include <string>

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

template<typename T>
void iter ( T* array, int ar_length, void (*function)(T& argument) )
{
    int i = -1;
    while (++i < ar_length)
        function(array[i]);
};

template<typename T>
void increment (T& argument)
{
    argument++;
}

template<typename T>
void display (T& argument)
{
    std::cout << argument << " ";
}