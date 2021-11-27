#pragma once

#include <iostream>

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
void swap (T& s1, T& s2)
{
    T temp;

    temp = s1;
    s1 = s2;
    s2 = temp;
}

template<typename T>
const T& min (const T& min1, const T& min2)
{
    return (min1 < min2 ? min1 : min2);
}

template<typename T>
const T& max (const T& max1, const T& max2)
{
    return (max1 > max2 ? max1 : max2);
}