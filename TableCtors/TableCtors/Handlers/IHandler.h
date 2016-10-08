#pragma once

#include <vector>
#include <string>

class CTable;
class IHandler
{
public:
    IHandler(std::vector<std::string>& inCommand);
    virtual ~IHandler();
protected:
    virtual void perform(std::vector<CTable*>& inFlyweightCache) = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

