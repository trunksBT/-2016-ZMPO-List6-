#pragma once

#include <string>
#include <vector>
#include <map>

#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

class CFlyweight
{
public:
    CFlyweight();
    ~CFlyweight();
    CODE interpretCommand(std::vector<std::string>& inCommand);
private:
    void releaseResources();
public:
    TableOfTables* shapeCache_;
    std::map<int, bool> shapeCacheIsInitialized_;
private:
    //static void updateIsInitializedShapeCache(int idx, bool newVal);
    //static void initShapeCache(int inCacheSize);
};

