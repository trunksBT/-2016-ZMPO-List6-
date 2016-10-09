#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"

class CTable;
class IHandler
{
public:
    IHandler(std::vector<std::string>& inCommand);
    virtual ~IHandler();
    virtual ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

