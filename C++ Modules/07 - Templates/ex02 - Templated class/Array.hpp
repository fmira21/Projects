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

template<typename T>
class Array
{
    private:
        unsigned int    _size;
        T*              _objArray;

    public:

        class outOfBoundsException : public std::exception
        {
            const char* what() const throw()
            {
                return ("Wrong index: the element is out of the array bounds.");
            }
        };

        Array ( void ) : _size(0), _objArray(NULL)
        {

        };

        Array ( unsigned int n )
        {
            this->_size = n;
            this->_objArray = new T[n];
            for (unsigned int i = 0; i < n; i++)
                this->_objArray[i] = 0;
        };

        Array ( int n )
        {
            this->_size = n;
            this->_objArray = new T[n];
            //for (int i = 0; i < n; i++)
            //    this->_objArray[i] = NULL;
        };

        Array ( const Array<T>& from )
        {
            this->_size = from._size;
            this->_objArray = new T[from._size]();
            for (unsigned int i = 0; i < from._size; i++)
                this->_objArray[i] = from._objArray[i];
        };

        ~Array ( void )
        {
            delete (this->_objArray); // Strings are on the stack!
        };

        Array<T>& operator=(const Array<T> &from)
        {
            if (this != &from)
            {
                if (this->_objArray)
                    delete(this->_objArray);
                this->_size = from._size;
                this->_objArray = new T[this->_size]();
                for (unsigned int i = 0; i < from._size; i++)
                    this->_objArray[i] = from._objArray[i];
            }

            return(*this);
        };

        T& operator[](const unsigned int index)
        {
            if (index >= this->_size)
                throw outOfBoundsException();

            return(this->_objArray[index]);
        };

        const T getIndexElement (const unsigned int index)
        {
            if (index >= this->_size)
                throw outOfBoundsException();

            return (this->_objArray[index]);
        }

        void setIndexElement (const unsigned int index, T toSet)
        {
            if (index >= this->_size)
                throw outOfBoundsException();

            this->_objArray[index] = toSet;
        }

        unsigned int size (void)
        {
            unsigned int i = 0;
            while (this->_objArray[i])
                i++;

            return (i + 1);
        };
};