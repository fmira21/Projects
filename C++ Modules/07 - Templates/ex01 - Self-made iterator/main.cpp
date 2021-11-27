#include "iter.hpp"

int main(void)
{
    // Integer case:

    std::cout << BOLDWHITE << "INTEGER:" << DEFAULT << std::endl << std::endl;

    int array_i[100];

    for (int i = 0; i < 100; i++)
        array_i[i] = i;

    std::cout << BOLDBLUE << "Initial int array: " << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;    
    ::iter(array_i, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    ::iter(array_i, 100, increment);
    
    std::cout << BOLDBLUE << "Int array after incrementation: " << DEFAULT << std::endl;

    std::cout << BOLDGREEN;    
    ::iter(array_i, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    // Double case:

    std::cout << BOLDWHITE << "DOUBLE:" << DEFAULT << std::endl << std::endl;

    double array_d[100];

    for (int i = 0; i < 100; i++)
        array_d[i] = i + 0.012 + (i / 0.057);

    std::cout << BOLDBLUE << "Initial double array: " << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;    
    ::iter(array_d, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    ::iter(array_d, 100, increment);
    
    std::cout << BOLDBLUE << "Double array after incrementation: " << DEFAULT << std::endl;

    std::cout << BOLDGREEN;    
    ::iter(array_d, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    // Float case:

    std::cout << BOLDWHITE << "FLOAT:" << DEFAULT << std::endl << std::endl;

    float array_f[100];

    for (int i = 0; i < 100; i++)
        array_f[i] = i + 0.012f + (i / 0.057f);

    std::cout << BOLDBLUE << "Initial float array: " << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;    
    ::iter(array_f, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    ::iter(array_f, 100, increment);
    
    std::cout << BOLDBLUE << "Float array after incrementation: " << DEFAULT << std::endl;

    std::cout << BOLDGREEN;    
    ::iter(array_f, 100, display);
    std::cout << DEFAULT << std::endl << std::endl;

    // Char case:

    std::cout << BOLDWHITE << "CHAR:" << DEFAULT << std::endl << std::endl;

    char array_c[90];

    for (int i = 0; i < 90; i++)
        array_c[i] = i + 33;

    std::cout << BOLDBLUE << "Initial char array: " << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;    
    ::iter(array_c, 90, display);
    std::cout << DEFAULT << std::endl << std::endl;

    ::iter(array_c, 90, increment);
    
    std::cout << BOLDBLUE << "Char array after incrementation: " << DEFAULT << std::endl;

    std::cout << BOLDGREEN;    
    ::iter(array_c, 90, display);
    std::cout << DEFAULT << std::endl << std::endl;

    // String case:

    std::cout << BOLDWHITE << "STD::STRING:" << DEFAULT << std::endl << std::endl;

    std::string array_s[4] = {"Oh", "hi", "Mark", "!"};

    std::cout << BOLDBLUE << "Initial string array: " << DEFAULT << std::endl;
    
    std::cout << BOLDGREEN;    
    ::iter(array_s, 4, display);
    std::cout << DEFAULT << std::endl << std::endl;

    // Invalid: we cannot increment a string.
    /* 
    ::iter(array_s, 4, increment);
    
    std::cout << BOLDBLUE << "String array after incrementation: " << DEFAULT << std::endl;

    std::cout << BOLDGREEN;    
    ::iter(array_s, 4, display);
    std::cout << DEFAULT << std::endl << std::endl;
    */
}