#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CRemoveAllHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS_ = 1;
    std::string PROPER_TYPES_OF_ARGS_ = "s";
public:
    CRemoveAllHandler(std::vector<std::string>& inCommand);
    virtual ~CRemoveAllHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
