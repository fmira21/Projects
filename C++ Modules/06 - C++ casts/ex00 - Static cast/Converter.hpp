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
#include <string>
#include <limits>
#include <cmath>

class Converter
{
    private:
        Converter (void);
        std::string _argument; // Just set the argv[1] here.

    public:
        Converter (std::string argument);
        Converter (const Converter &from);
        ~Converter (void);

        Converter   &operator=(const Converter &from);

        const std::string& getArgument(void) const;

        char getChar (void) const;
        long getInt (void) const;
        float getFloat (void) const;
        double getDouble (void) const;

        void processChar(void);
        void processInt(void);
        void processFloat(void);
        void processDouble(void);
};