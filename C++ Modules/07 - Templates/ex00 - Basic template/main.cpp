/*
A really great MS reference: https://docs.microsoft.com/ru-ru/cpp/cpp/templates-cpp?view=msvc-170
*/

#include "whatever.hpp"

int main (void)
{
    // Valid types:

    // Integer
    int a_i = 10;
    int b_i = 5;

    std::cout << BOLDBLUE << "Before swap:" << std::endl;

    std::cout << BOLDGREEN << "int A = " << BOLDMAGENTA << a_i << std::endl;
    std::cout << BOLDGREEN << "int B = " << BOLDMAGENTA << b_i << std::endl;

    swap<int>(a_i, b_i);

    std::cout << BOLDBLUE << "After swap:" << std::endl;

    std::cout << BOLDGREEN << "int A = " << BOLDMAGENTA << a_i << std::endl;
    std::cout << BOLDGREEN << "int B = " << BOLDMAGENTA << b_i << std::endl;


    std::cout << BOLDGREEN << "Min int: " << BOLDMAGENTA << min<int>(a_i, b_i) << std::endl;
    std::cout << BOLDGREEN << "Max int: " << BOLDMAGENTA << max<int>(a_i, b_i) << std::endl;
    std::cout << std::endl;

    // Float

    float a_f = 10.005f;
    float b_f = 5.01f;

    std::cout << BOLDBLUE << "Before swap:" << std::endl;

    std::cout << BOLDGREEN << "float A = " << BOLDMAGENTA << a_f << std::endl;
    std::cout << BOLDGREEN << "float B = " << BOLDMAGENTA << b_f << std::endl;

    swap<float>(a_f, b_f);

    std::cout << BOLDBLUE << "After swap:" << std::endl;

    std::cout << BOLDGREEN << "float A = " << BOLDMAGENTA << a_f << std::endl;
    std::cout << BOLDGREEN << "float B = " << BOLDMAGENTA << b_f << std::endl;


    std::cout << BOLDGREEN << "Min float: " << BOLDMAGENTA << min<float>(a_f, b_f) << std::endl;
    std::cout << BOLDGREEN << "Max float: " << BOLDMAGENTA << max<float>(a_f, b_f) << std::endl;
    std::cout << std::endl;


    // Double

    double a_d = 10.014;
    double b_d = 5.109;

    std::cout << BOLDBLUE << "Before swap:" << std::endl;

    std::cout << BOLDGREEN << "double A = " << BOLDMAGENTA << a_d << std::endl;
    std::cout << BOLDGREEN << "double B = " << BOLDMAGENTA << b_d << std::endl;

    swap<double>(a_d, b_d);

    std::cout << BOLDBLUE << "After swap:" << std::endl;

    std::cout << BOLDGREEN << "double A = " << BOLDMAGENTA << a_d << std::endl;
    std::cout << BOLDGREEN << "double B = " << BOLDMAGENTA << b_d << std::endl;


    std::cout << BOLDGREEN << "Min double: " << BOLDMAGENTA << min<double>(a_d, b_d) << std::endl;
    std::cout << BOLDGREEN << "Max double: " << BOLDMAGENTA << max<double>(a_d, b_d) << std::endl;
    std::cout << std::endl;

    // Char

    char a_c = 'A';
    char b_c = 'X';

    std::cout << BOLDBLUE << "Before swap:" << std::endl;

    std::cout << BOLDGREEN << "char A = " << BOLDMAGENTA << a_c << std::endl;
    std::cout << BOLDGREEN << "char B = " << BOLDMAGENTA << b_c << std::endl;

    swap<char>(a_c, b_c);

    std::cout << BOLDBLUE << "After swap:" << std::endl;

    std::cout << BOLDGREEN << "char A = " << BOLDMAGENTA << a_c << std::endl;
    std::cout << BOLDGREEN << "char B = " << BOLDMAGENTA << b_c << std::endl;


    std::cout << BOLDGREEN << "Min char: " << BOLDMAGENTA << min<char>(a_c, b_c) << std::endl;
    std::cout << BOLDGREEN << "Max char: " << BOLDMAGENTA << max<char>(a_c, b_c) << std::endl;
    std::cout << std::endl;

    // String

    std::string a_s = "Str1";
    std::string b_s = "Str2";

    std::cout << BOLDBLUE << "Before swap:" << std::endl;

    std::cout << BOLDGREEN << "std::string A = " << BOLDMAGENTA << a_s << std::endl;
    std::cout << BOLDGREEN << "std::string B = " << BOLDMAGENTA << b_s << std::endl;

    ::swap<std::string>(a_s, b_s); // Remove :: and see what compiler will say

    std::cout << BOLDBLUE << "After swap:" << std::endl;

    std::cout << BOLDGREEN << "std::string A = " << BOLDMAGENTA << a_s << std::endl;
    std::cout << BOLDGREEN << "std::string B = " << BOLDMAGENTA << b_s << std::endl;


    std::cout << BOLDGREEN << "Min std::string: " << BOLDMAGENTA << ::min<std::string>(a_s, b_s) << std::endl;
    std::cout << BOLDGREEN << "Max std::string: " << BOLDMAGENTA << ::max<std::string>(a_s, b_s) << std::endl;
    std::cout << std::endl;
}


// Subject main:

/*
int main( void ) {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}
*/