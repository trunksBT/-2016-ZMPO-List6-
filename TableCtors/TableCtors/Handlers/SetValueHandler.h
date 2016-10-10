#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class SetValueHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 4;
    std::string PROPER_TYPES_OF_ARGS = "siii";
public:
    SetValueHandler(std::vector<std::string>& inCommand);
    virtual ~SetValueHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
