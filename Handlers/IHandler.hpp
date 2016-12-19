#pragma once

#include <vector>
#include <string>
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

class IHandler
{
public:
    IHandler(std::vector<std::string>& inCommand);
    virtual ~IHandler();
    CODE checkArgsAndPerform(InitializedCTable inCache);
    virtual CODE performOn(TableOfTables* inCache,
        std::map<int, bool>& inIsInitialized) = 0;
    virtual const int getProperAmountOfArgs() const noexcept = 0;
    virtual std::string getProperTypesOfArgs() const noexcept = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

