#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class GetValueHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 3;
    std::string PROPER_TYPES_OF_ARGS = "sii";
public:
    GetValueHandler(std::vector<std::string>& inCommand);
    virtual ~GetValueHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};