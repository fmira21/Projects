/*
 Nice references: 
 * https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
 * https://tproger.ru/articles/stl-cpp/
 * https://www.cppreference.com/Cpp_STL_ReferenceManual.pdf
 * https://en.cppreference.com/w/cpp/container
*/

#include "easyfind.hpp"

// Let's try with three sequence containers:
#include <vector>
#include <list>
#include <deque>

int main (void)
{
    std::vector<int>    vec;
    std::list<int>      lst;
    std::deque<int>     deq;
    
    srand(time(NULL));

    // Vector cases:

    std::cout << BOLDWHITE << "VECTOR:" << DEFAULT << std::endl;
    for( int i = 0; i < 10; i++ ) {
        vec.push_back( i + (rand() % 3) );
    }
    std::cout << std::endl << BOLDBLUE << "Initial pseudo-randomized vector:" << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;
    for( int i = 0; i < 10; i++ ) {
        std::cout << vec[i] << " ";
    }
    std::cout << DEFAULT << std::endl;

    std::cout << std::endl << BOLDBLUE << "Trying to find 4..." << DEFAULT << std::endl;
    try
    {
        easyfind(vec, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // List cases:

    std::cout << std::endl << BOLDWHITE << "LIST:" << DEFAULT << std::endl;
    for( int i = 0; i < 10; i++ ) {
        lst.push_back( i + (rand() % 3) );
    }
    std::cout << std::endl << BOLDBLUE << "Initial pseudo-randomized list:" << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;
    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i) // It's quite challenging to get the contents of the list. In Python also, btw.
        std::cout << *i << " ";
    std::cout << DEFAULT << std::endl;
    
    std::cout << std::endl << BOLDBLUE << "Trying to find 4..." << DEFAULT << std::endl;
    try
    {
        easyfind(lst, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Deque cases:

    std::cout << std::endl << BOLDWHITE << "DEQUE:" << DEFAULT << std::endl;
    for( int i = 0; i < 10; i++ ) {
        deq.push_back( i + (rand() % 3) );
    }
    std::cout << std::endl << BOLDBLUE << "Initial pseudo-randomized list:" << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;
    for (int i = 0; i < 10; ++i) {
        std::cout << deq[i] << ' ';
    }
    std::cout << DEFAULT << std::endl;
    
    std::cout << std::endl << BOLDBLUE << "Trying to find 4..." << DEFAULT << std::endl;
    try
    {
        easyfind(lst, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}