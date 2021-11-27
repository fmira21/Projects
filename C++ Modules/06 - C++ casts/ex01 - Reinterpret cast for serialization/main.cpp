#include "main.hpp"

/* 
    Here, we can use reintrpret_cast. Why?
    It can be compiled and will perform cast in any way - it's usable for re-typing.

    uintptr_t -> Data *
    Data * -> uintptr_t

    In fact, it's the sake of serialization: we receive a raw byte stream as a result of re-interpretation.
*/

// Invalid casts:

// 1st case: we are unable to perform static cast for undefined types (as Data)

/*
uintptr_t serialize(Data* ptr) // error: static_cast from 'Data *' (aka 's_data *') to 'uintptr_t' (aka 'unsigned long') is not allowed
{
	return (static_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (static_cast<Data *>(raw));
}
*/

// Second case: we are unable to cast dynamically into a not-pointer

/*
uintptr_t serialize(Data* ptr) // error: invalid target type 'uintptr_t' (aka 'unsigned long') for dynamic_cast; target type must be a reference or pointer type to a defined class
{
	return (dynamic_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (dynamic_cast<Data *>(raw));
}
*/

// Valid cast: 


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main (void)
{
    Data* ourdata = new Data(); // Let's call the struct via the pointer - just due to the serialize prototype.

    uintptr_t serialized = serialize(ourdata); // Unsigned long to store a data pointer. Capable to store raw sequence of bytes.
    Data* deserialized = deserialize(serialized);

    std::cout << BOLDYELLOW << "Variable address: " << BOLDMAGENTA << ourdata << DEFAULT << std::endl;
    std::cout << BOLDYELLOW << "Unsigned int data (after serialization): " << BOLDMAGENTA << serialized << DEFAULT << std::endl;
    //std::cout << BOLDYELLOW << "Raw bytes dump (after serialization): " << BOLDMAGENTA << ser_bytes << DEFAULT << std::endl;
    std::cout << BOLDYELLOW << "Original data (before serialization or after de-serialization): " << BOLDMAGENTA << deserialized << DEFAULT << std::endl;

    delete ourdata; // Struct is on the heap, deallocate.
    
    return (0);
}