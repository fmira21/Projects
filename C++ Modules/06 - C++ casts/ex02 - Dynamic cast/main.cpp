#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
Here, we use dynamic_cast to cast a data from one * or & to another.
It performs a runtime check to ensure validity of the cast.

If we attempt to dynamic_cast to a *type that is not a type of an object
to be casted, the result of a cast will be NULL.

If we attempt to dynamic_cast to a &type that is not a type of an object
to be casted, the cast will throw a bad_cast exception.

So, it's easy to handle the conversions.
*/

int rollNumber(void) // 1, 2 or 3
{
    srand(time(NULL));

    int ret = (rand() % 3) + 1;

    return (ret);
}

Base* generate (void)
{
    Base* generated;

    switch (rollNumber())
    {
        case 1 : generated = new A; break;
        case 2 : generated = new B; break;
        case 3 : generated = new C; break;
    }
    
    return (generated);
}

void identify (Base* p)
{
    A* a_ptr = dynamic_cast<A*>(p);
    B* b_ptr = dynamic_cast<B*>(p);
    C* c_ptr = dynamic_cast<C*>(p);

    if (a_ptr != NULL)
        std::cout << BOLDRED << "A" << DEFAULT << std::endl;
    else if (b_ptr != NULL)
        std::cout << BOLDBLUE << "B" << DEFAULT << std::endl;
    else if (c_ptr != NULL)
        std::cout << BOLDGREEN << "C" << DEFAULT << std::endl;
    else
        std::cout << BOLDRED << "I dunno, lol (O_o)" << DEFAULT << std::endl;

}

void identify (Base& p)
{
    try
    {
        A a_ref = dynamic_cast<A&>(p);
        std::cout << BOLDRED << "A" << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
        // Silent exception.
    }

    try
    {
        B b_ref = dynamic_cast<B&>(p);
        std::cout << BOLDBLUE << "B" << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
        // Silent exception.
    }

    try
    {
        C c_ref = dynamic_cast<C&>(p);
        std::cout << BOLDGREEN << "C" << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
        // Silent exception.
    }
}

int main (void)
{
    Base* ourbase = generate();

    std::cout << BOLDWHITE << "void identify (Base* p): " << DEFAULT << std::endl;
    identify (ourbase);

    std::cout << BOLDWHITE << "void identify (Base& p): " << DEFAULT << std::endl;
    identify (ourbase);
}