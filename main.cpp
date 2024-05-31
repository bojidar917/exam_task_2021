#include <iostream>
#include <fstream>

#include "Configuration.h"

void writeToFileTest()
{
    std::ofstream myFile;
    myFile.open("example.txt");
    myFile << createConfiguration();

    //⚠️ here we have memory leak, because we do not delete the createConfiguration
    //this is only for testing purposes
}

void displayToConsoleTest()
{
    std::cout << createConfiguration();

    //⚠️ here we have memory leak, because we do not delete the createConfiguration
    //this is only for testing purposes
}

int main()
{
    Configuration* configuration = createConfiguration();
    
    std::cout << "Select file name to save: ";
    std::string fileName;
    std::cin >> fileName;

    std::ofstream myFile;
    myFile.open(fileName + ".txt");
    myFile << configuration;
    std::cout << configuration << std::endl;
    
    delete configuration;

    return 0;
}