#pragma once

#include <vector>
#include <string>

class CTable;
class RAIIFlyweightCTable
{
public:
   RAIIFlyweightCTable(std::vector<std::string>& inCommand);
   RAIIFlyweightCTable(std::vector<std::string>& inCommand, std::vector<CTable*>& inCache);
    ~RAIIFlyweightCTable();
};
