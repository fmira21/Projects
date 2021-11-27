#include "Karen.hpp"

void Karen::complain (std::string level)
{
    int index = 0;
    void (Karen::*complains[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
    std::string karenLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // String array for simple mapping

    for(int i = 0; i < 4; i++) // Mapping loop
    {
        if(!level.compare(std::to_string(i + 1)) || !level.compare(karenLevels[i]))
            index = i + 1;
    }
    
    switch(index){
        case 1 ... 4:
            (this->*complains[index - 1])();
            break;
        default:
            std::cout << BOLDRED << "Error: " << DEFAULT << "Invalid input. Karen has 1...4 levels of complains." << std::endl;
            break;
    }
}

void Karen::debug( void )
{
    std::cout << BLUE << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << DEFAULT << std::endl;
}

void Karen::info( void )
{
    std::cout << DEFAULT << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning ( void )
{
    std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month!" << DEFAULT << std::endl; 
}

void Karen::error ( void )
{
    std::cout << RED << "This is unacceptable, I want to speak to the manager now." << DEFAULT << std::endl; 
}