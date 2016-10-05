#pragma once

#include <vector>
#include <string>

class RAIIFlyweightCTable
{
public:
    RAIIFlyweightCTable(std::vector<std::string>& inCommand);
    ~RAIIFlyweightCTable();
};
