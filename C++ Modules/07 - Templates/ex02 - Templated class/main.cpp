#include "../ex01/iter.hpp" // C'mon, let's go hard.

#include "Array.hpp"

template<typename T>
void randomize (T& argument)
{
    argument = rand();
}

template<typename T>
void randomizeString (T& argument) 
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;

    tmp_s.reserve(5);

    for (int i = 0; i < 5; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    argument = tmp_s;
}

template<typename T>
void randomizeAlNum (T& argument) 
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    argument = alphanum [rand()  % (sizeof(alphanum) - 1)];
}

enum stringCode
{
    sInt,
    sFloat,
    sChar,
    sDouble,
    sString,
    sOther
};

stringCode mapIt (std::string const& input)
{
    if (input == "int") return sInt;
    if (input == "float") return sFloat;
    if (input == "char") return sChar;
    if (input == "double") return sDouble;
    if (input == "string") return sString;
    return sOther;
}

// NB: String is an invalid case, because the overloaded constructor does not allow to work with strings.
// Nevertheless, I've made one more constructor to prove it works.
// To start this case without any error, you have to comment out the delete string in the destructor: everything for the strings stays on the stack and does not require allocation.

void testString( void )
{
    std::cout << BOLDMAGENTA << ":::STRING TEST CASE:::" << DEFAULT << std::endl << std::endl;


    Array<std::string> classy ((int)100); // Via the class
    std::string* analogue = new std::string[100]; // Via the pointer
    // Fill operations:

    srand(time(NULL)); // Update the seed ONCE! before the randomization.

    iter(analogue, 100, randomizeString); // Cannot access the class via iter, because it needs deeper intervention into the iter itself.

    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        randomizeString(classy[i]);     // Template still works
    
    // Display operations: Numbers are pseudo-randomized and will be different

    std::cout << BOLDWHITE << "Analogue:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    iter(analogue, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Assignation operation:
    Array<std::string> assigned = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Assigned classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(assigned[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Assignation integrity check:" << DEFAULT << std::endl;
    int i;

    for (i = 0; i < 100; i++)
    {
        if (classy[i] != assigned[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly assigned." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Copy operation:
    Array<std::string> copy = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Copied classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(copy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Copy integrity check:" << DEFAULT << std::endl;
    for (i = 0; i < 100; i++)
    {
        if (classy[i] != copy[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly copied." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Try out of bounds:

    std::cout << BOLDWHITE << "Out of bounds exception:" << DEFAULT << std::endl;
    try
    {
        classy[-1] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        classy[101] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //delete [] analogue;

}

void testDouble( void )
{
    std::cout << BOLDMAGENTA << ":::DOUBLE TEST CASE:::" << DEFAULT << std::endl << std::endl;


    Array<double> classy ((unsigned int)100); // Via the class
    double* analogue = new double[100]; // Via the pointer
    // Fill operations:

    srand(time(NULL)); // Update the seed ONCE! before the randomization.

    iter(analogue, 100, randomize); // Cannot access the class via iter, because it needs deeper intervention into the iter itself.

    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        randomize(classy[i]);     // Template still works
    
    // Display operations: Numbers are pseudo-randomized and will be different

    std::cout << BOLDWHITE << "Analogue:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    iter(analogue, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Assignation operation:
    Array<double> assigned = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Assigned classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(assigned[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Assignation integrity check:" << DEFAULT << std::endl;
    int i;

    for (i = 0; i < 100; i++)
    {
        if (classy[i] != assigned[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly assigned." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Copy operation:
    Array<double> copy = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Copied classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(copy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Copy integrity check:" << DEFAULT << std::endl;
    for (i = 0; i < 100; i++)
    {
        if (classy[i] != copy[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly copied." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Try out of bounds:

    std::cout << BOLDWHITE << "Out of bounds exception:" << DEFAULT << std::endl;
    try
    {
        classy[-1] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        classy[101] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete [] analogue;

}

void testChar( void )
{
    std::cout << BOLDMAGENTA << ":::CHAR TEST CASE:::" << DEFAULT << std::endl << std::endl;


    Array<char> classy ((unsigned int)100); // Via the class
    char* analogue = new char[100]; // Via the pointer
    // Fill operations:

    srand(time(NULL)); // Update the seed ONCE! before the randomization.

    iter(analogue, 100, randomizeAlNum); // Cannot access the class via iter, because it needs deeper intervention into the iter itself.

    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        randomizeAlNum(classy[i]);     // Template still works
    
    // Display operations: Numbers are pseudo-randomized and will be different

    std::cout << BOLDWHITE << "Analogue:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    iter(analogue, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Assignation operation:
    Array<char> assigned = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Assigned classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(assigned[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Assignation integrity check:" << DEFAULT << std::endl;
    int i;

    for (i = 0; i < 100; i++)
    {
        if (classy[i] != assigned[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly assigned." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Copy operation:
    Array<char> copy = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Copied classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(copy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Copy integrity check:" << DEFAULT << std::endl;
    for (i = 0; i < 100; i++)
    {
        if (classy[i] != copy[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly copied." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Try out of bounds:

    std::cout << BOLDWHITE << "Out of bounds exception:" << DEFAULT << std::endl;
    try
    {
        classy[-1] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        classy[101] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete [] analogue;
}

void testFloat( void )
{
    std::cout << BOLDMAGENTA << ":::FLOAT TEST CASE:::" << DEFAULT << std::endl << std::endl;


    Array<float> classy ((unsigned int)100); // Via the class
    float* analogue = new float[100]; // Via the pointer
    // Fill operations:

    srand(time(NULL)); // Update the seed ONCE! before the randomization.

    iter(analogue, 100, randomize); // Cannot access the class via iter, because it needs deeper intervention into the iter itself.

    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        randomize(classy[i]);     // Template still works
    
    // Display operations: Numbers are pseudo-randomized and will be different

    std::cout << BOLDWHITE << "Analogue:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    iter(analogue, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Assignation operation:
    Array<float> assigned = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Assigned classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(assigned[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Assignation integrity check:" << DEFAULT << std::endl;
    int i;

    for (i = 0; i < 100; i++)
    {
        if (classy[i] != assigned[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly assigned." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Copy operation:
    Array<float> copy = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Copied classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(copy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Copy integrity check:" << DEFAULT << std::endl;
    for (i = 0; i < 100; i++)
    {
        if (classy[i] != copy[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly copied." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Try out of bounds:

    std::cout << BOLDWHITE << "Out of bounds exception:" << DEFAULT << std::endl;
    try
    {
        classy[-1] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        classy[101] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete [] analogue;
}

void testInt( void )
{
    std::cout << BOLDMAGENTA << ":::INTEGER TEST CASE:::" << DEFAULT << std::endl << std::endl;

    Array<int> classy ((unsigned int)100); // Via the class
    int* analogue = new int[100]; // Via the pointer
    // Fill operations:

    srand(time(NULL)); // Update the seed ONCE! before the randomization.

    iter(analogue, 100, randomize); // Cannot access the class via iter, because it needs deeper intervention into the iter itself.

    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        randomize(classy[i]);     // Template still works
    
    // Display operations: Numbers are pseudo-randomized and will be different

    std::cout << BOLDWHITE << "Analogue:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    iter(analogue, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Assignation operation:
    Array<int> assigned = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Assigned classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(assigned[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Assignation integrity check:" << DEFAULT << std::endl;
    int i;

    for (i = 0; i < 100; i++)
    {
        if (classy[i] != assigned[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly assigned." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Copy operation:
    Array<int> copy = classy;

    std::cout << BOLDWHITE << "Initial classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(classy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << BOLDWHITE << "Copied classy:" << DEFAULT << std::endl;
    std::cout << BOLDGREEN;
    for (int i = 0; i < 100; i++) // Better to do it in a more conventional way
        display(copy[i]);
    std::cout << DEFAULT << std::endl << std::endl;

    // Integrity check:
    std::cout << BOLDWHITE << "Copy integrity check:" << DEFAULT << std::endl;
    for (i = 0; i < 100; i++)
    {
        if (classy[i] != copy[i])
        {
            std::cout << BOLDRED << "Something went wrong, invalid assignation of the " << i << " array element" << DEFAULT << std::endl;
            return ;
        }
    }
    std::cout << BOLDBLUE << "OK. All " << i << " elements are properly copied." << DEFAULT << std::endl;
    std::cout << DEFAULT << std::endl << std::endl;

    // Try out of bounds:

    std::cout << BOLDWHITE << "Out of bounds exception:" << DEFAULT << std::endl;
    try
    {
        classy[-1] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        classy[101] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete [] analogue;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << BOLDRED << "Error: enter the desired type (int, float, char, double)." << std::endl;
        return (0);
    }    
    switch (mapIt(argv[1]))
    {
        case sInt: 
            testInt(); break;
        case sFloat:
            testFloat(); break;
        case sChar:
            testChar(); break;
        case sDouble:
            testDouble(); break;
        case sString:
            testString(); break;
        case sOther:
            std::cout << BOLDRED << "Error: Invalid type." << DEFAULT << std::endl; return (0);
    }

    return (0);
}