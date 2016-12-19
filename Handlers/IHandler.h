#pragma once

#include <vector>
#include <string>
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

class IHandler
{
public:
    //IHandler(std::vector<std::string>& inCommand);
    //virtual ~IHandler();
    //CODE checkCorrectnessAndPerform(std::vector<CTable<T>*>& inCache);
    //virtual CODE performOn(std::vector<CTable<T>*>& inCache) = 0;
    //virtual const int getProperAmountOfArgs() = 0;
    //virtual std::string getProperTypesOfArgs() = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

