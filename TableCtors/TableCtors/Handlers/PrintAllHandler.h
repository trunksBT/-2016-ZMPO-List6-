#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CPrintAllHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 1;
    std::string PROPER_TYPES_OF_ARGS = "s";
public:
    CPrintAllHandler(std::vector<std::string>& inCommand);
    virtual ~CPrintAllHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCFlyweightCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
