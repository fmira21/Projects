#include "span.hpp"


int main()
{
    srand(time(NULL));
    Span sp = Span(100000); // Wanted to make rand, but too long to fill

    std::cout << BOLDGREEN << "Span size: " <<  sp.getSize() << std::endl;

    for (unsigned int i = 0; i < sp.getSize(); i++)
    {
        sp.addNumber(rand());
    }
    std::cout << DEFAULT << std::endl;
    try
    {
        sp.addNumber(rand());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << BOLDGREEN << "Shortest span: " << BOLDMAGENTA << sp.shortestSpan() << std::endl;
        std::cout << BOLDGREEN << "Longest span: " << BOLDMAGENTA << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Subject main:

/*
int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        //sp.addNumber(10); // Catchable
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
*/