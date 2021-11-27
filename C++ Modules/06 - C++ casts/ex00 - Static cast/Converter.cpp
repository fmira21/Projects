#include "Converter.hpp"

Converter::Converter (std::string argument) : _argument(argument)
{

}

Converter::Converter (const Converter &from)
{
    *this = from;
}

Converter::~Converter (void)
{

}

Converter &Converter::operator=(const Converter &from)
{
	if (this == &from)
		return *this;
	return *this;
}

const std::string& Converter::getArgument (void) const
{
    return (_argument);
}

/**********************************************************************/

void Converter::processChar (void)
{
    char toPrint = '\0';

    std::cout << "char: ";

    try
    {
        if (_argument.length() == 1 && !std::isdigit(_argument[0]))
        {
            toPrint = static_cast<char>(_argument[0]);
        }
        else if (std::stoi(_argument) >= 0 && std::stoi(_argument) <= 127)
        {
            toPrint = static_cast<char>(std::stoi(_argument));
        }
        else
            std::cout << "impossible" << std::endl;

        if (std::isprint(toPrint))
            std::cout << toPrint << std::endl;
        else
            std::cout << "non-displayable" << std::endl;
    }
    catch(const std::exception& e) // Out-of-range exception
    {
        std::cout << "impossible" << std::endl;
    }
}

void Converter::processInt(void)
{
    std::cout << "int: ";

    try
    {
        if (_argument.length() == 1 && !std::isdigit(_argument[0]) && std::isprint(_argument[0]))
        {
            std::cout << static_cast<int>(_argument[0]) << std::endl;
        }
        else
            std::cout << static_cast<int>(std::stoi(_argument)) << std::endl;;
    }
    catch(const std::exception& e) // Out-of-range exception
    {
        std::cout << "impossible" << std::endl;
    }
}

void Converter::processFloat(void)
{
    float toPrint;
    std::cout << "float: ";

    try
    {
        if (_argument.length() == 1 && !std::isdigit(_argument[0]) && std::isprint(_argument[0]))
        {
            toPrint = static_cast<float>(_argument[0]);
        }
        else
            toPrint = static_cast<float>(std::stof(_argument));
        
        if (roundf(toPrint) == toPrint)
            std::cout << toPrint << ".0f" << std::endl;
        else
            std::cout << toPrint << "f" << std::endl;

    }
    catch(const std::exception& e) // Out-of-range exception
    {
        std::cout << "impossible" << std::endl;
    }
}

void Converter::processDouble(void)
{
    double toPrint;
    std::cout << "double: ";

    try
    {
        if (_argument.length() == 1 && !std::isdigit(_argument[0]) && std::isprint(_argument[0]))
        {
            toPrint = static_cast<double>(_argument[0]);
        }
        else
            toPrint = static_cast<double>(std::stod(_argument));
        
        if (roundf(toPrint) == toPrint)
            std::cout << toPrint << ".0" << std::endl;
        else
            std::cout << toPrint << std::endl;
    }
    catch(const std::exception& e) // Out-of-range exception
    {
        std::cout << "impossible" << std::endl;
    }
}