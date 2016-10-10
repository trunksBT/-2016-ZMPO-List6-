#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateCopyHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 3;
    std::string PROPER_TYPES_OF_ARGS = "sii";
public:
    CreateCopyHandler(std::vector<std::string>& inCommand);
    virtual ~CreateCopyHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
