#pragma once

#include <string>
#include <vector>
#include <ElementsAndTables/CTable.hpp>
#include <Utils/Utils.hpp>

class CFlyweight
{
public:
    CFlyweight();
    CFlyweight(std::vector<std::string>& inCommand,
        std::vector<CTable*>& inCache);
    ~CFlyweight();
public:
    static void createCFlyweight(int inSize);
    static void createCFlyweight(std::vector<CTable*>& inCache);
    static ERROR_CODE interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
   static void releaseResources(std::vector<CTable*>& inCache);
private:
    static std::vector<CTable*> cache_;
};

