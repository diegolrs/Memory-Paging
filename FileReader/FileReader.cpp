#include "FileReader.hpp"

std::vector<int> FileReader::ReadFile(std::string address)
{
    std::string myText;
    std::ifstream myFile(address);

    if(!myFile.is_open())
    {
        throw std::invalid_argument("Could not open file at address " + address);
    }  

    std::vector<int> allInputs;
    while (getline(myFile, myText)) 
    {
        int input = std::stoi(myText);
        allInputs.push_back(input);
    }

    myFile.close();

    return allInputs;
}