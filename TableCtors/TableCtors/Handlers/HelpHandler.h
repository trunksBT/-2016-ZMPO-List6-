#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CHelpHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS_ = 1;
    std::string PROPER_TYPES_OF_ARGS_ = "s";
public:
    CHelpHandler(std::vector<std::string>& inCommand);
    virtual ~CHelpHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
