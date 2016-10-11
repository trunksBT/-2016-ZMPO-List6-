#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CGetNameHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 2;
    std::string PROPER_TYPES_OF_ARGS = "si";
public:
    CGetNameHandler(std::vector<std::string>& inCommand);
    virtual ~CGetNameHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCCFlyweightCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
