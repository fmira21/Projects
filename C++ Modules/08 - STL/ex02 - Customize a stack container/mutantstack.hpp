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
#include <stack>
#include <algorithm>
#include <deque> // Let's implement standard iterators from the deque class. It has conventional and reverse iterators (+ const overload for each)

// Here, the full description: https://en.cppreference.com/w/cpp/container/stack

template<typename T>

class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator iterator; // Define iterators from the deque
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

        MutantStack( void ) : std::stack<T>()
        {

        };

        MutantStack( const MutantStack<T> &from )
        {
            *this = std::stack<T>(from);
        };

        ~MutantStack( void )
        {

        };

        MutantStack<T> &operator=( const MutantStack<T> &from )
        {
            if(this != &from)
                return (*this);
            return (*this);
        };

// Conventional iterator methods:

        iterator				begin(void)
        {
            return(MutantStack<T>::c.begin());
        };

		iterator				end(void)
        {
            return(MutantStack<T>::c.end());
        };

// Reverse iterator methods:

		reverse_iterator		rbegin(void)
        {
            return(MutantStack<T>::c.rbegin());
        };

		reverse_iterator		rend(void)
        {
            return(MutantStack<T>::c.rend());
        };

// Const iterator methods:

		const_iterator			begin(void) const
        {
            return(MutantStack<T>::c.begin());
        };

		const_iterator			end(void) const
        {
            return(MutantStack<T>::c.end());
        };

// Const reverse iterator methods:

		const_reverse_iterator	rbegin(void) const
        {
            return(MutantStack<T>::c.rbegin());
        };

		const_reverse_iterator	rend(void) const
        {
            return(MutantStack<T>::c.rend());
        };
};