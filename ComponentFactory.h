#include <iostream>
#include <string.h>

#include "Component.h"
#include "Cpu.h"
#include "Ram.h"

inline Component* componentFactory()
{
    std::cout << "input type of the component (CPU or RAM)" << std::endl;
    std::string type;
    std::cin >> type;

    try
    {
        if(type == "CPU")
        {
            std::string label;
            std::cin >> label;
            unsigned short cores;
            std::cin >> cores;
            unsigned short clockSpeed;
            std::cin >> clockSpeed;

            return new Cpu(label, cores, clockSpeed);
        }
        if(type == "RAM")
        {
            std::string label;
            std::cin >> label;
            unsigned short capacity;
            std::cin >> capacity;

            return new Ram(label, capacity);    
        }
    }
    catch(...)
    {
        return nullptr;
    }  
}