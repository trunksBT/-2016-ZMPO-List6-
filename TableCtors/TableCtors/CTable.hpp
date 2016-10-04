#pragma once

#include <string>

class CTable
{
private:
    std::string name_;
public:
    CTable();
    CTable(CTable& inTable);
    CTable(std::string inName);
    ~CTable();
};

