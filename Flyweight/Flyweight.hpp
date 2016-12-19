#pragma once

#include <string>
#include <vector>
#include <map>

#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

class CFlyweight
{
public:
    ~CFlyweight();
    CODE interpretCommand(std::vector<std::string>& inCommand);
    void releaseResources();
private:
public:
    TableOfTables* shapeCache_ = nullptr;
    std::map<int, bool> shapeCacheIsInitialized_;
};

