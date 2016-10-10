#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class RemoveAllHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 1;
public:
    RemoveAllHandler(std::vector<std::string>& inCommand);
    virtual ~RemoveAllHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
