#pragma once

#include <vector>
#include <string>

class CTable;
class RAIIFlyweightCTable
{
public:
    static void receiveCommand(std::vector<std::string>& inCommand);
public:
    RAIIFlyweightCTable(std::vector<std::string>& inCommand);
    RAIIFlyweightCTable(std::vector<std::string>& inCommand, std::vector<CTable*>& inCache);
    ~RAIIFlyweightCTable();
};
