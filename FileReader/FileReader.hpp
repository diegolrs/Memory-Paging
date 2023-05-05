#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

namespace FileReader
{
    std::vector<int> ReadFile(std::string address);
};