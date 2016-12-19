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
    static void releaseResources();
private:
    static CTable<CTable<int>>* shapeCache_;
    static std::map<int, bool> shapeCacheIsInitialized_;
private:
    //static void updateIsInitializedShapeCache(int idx, bool newVal);
    //static void initShapeCache(int inCacheSize);
};

