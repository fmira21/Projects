#include "header.hpp"

std::string replace(std::string current_string, std::string s1, std::string s2)
{
    size_t pos;

    pos = current_string.find(s1);
    while(pos != std::string::npos)
    {
        current_string.erase(pos, s1.length());
        current_string.insert(pos, s2);
        pos = current_string.find(s1, pos + s2.size());
    }
    
    return (current_string);
}



int main (int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << RED << "Error: " << DEFAULT << "Enter the filename and two strings as arguments.\nExample: " << YELLOW << "./replace filename string1 string2." << DEFAULT << std::endl;
        return 0;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string current_string;

    if (filename.empty())
    {
        std::cout << RED << "Error: " << DEFAULT << "Filename should not be empty!" << DEFAULT << std::endl;
        return 0;
    }

    if (s1.empty() || s2.empty())
    {
        std::cout << RED << "Error: " << DEFAULT << "Strings should not be empty!" << DEFAULT << std::endl;
        return 0;
    }

    std::ifstream source; // Ifstream: input file stream (open for reading)
    std::ofstream output; // Ofstream: output file stream (open for writing)

    source.open(filename);

    if (!source)
    {
        std::cout<< RED << "Error: " << DEFAULT << "Could not open the source file!" << DEFAULT << std::endl;
        return 0;
    }

    output.open(filename + ".replace");

    if (!output)
    {
        std::cout<< RED << "Error: " << DEFAULT << "Could not create the destination file!" << DEFAULT << std::endl;
        return 0;
    }

    while (getline(source, current_string))
        output << replace(current_string, s1, s2) << std::endl;
    return 0;
}