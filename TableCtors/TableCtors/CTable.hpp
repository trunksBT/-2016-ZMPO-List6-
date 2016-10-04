#pragma once

#include <string>
#include <vector>

class CTable
{
public:
    CTable();
    CTable(CTable& inVal);
    CTable(std::string inVal);
    ~CTable();
public:
    void setName(std::string inVal);
public:
    static void releaseResources(std::vector<CTable*> &tables);
private:
    std::string name_;
};

