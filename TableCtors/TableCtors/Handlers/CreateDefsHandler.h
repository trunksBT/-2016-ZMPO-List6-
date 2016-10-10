#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateDefsHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 2;
    std::string PROPER_TYPES_OF_ARGS = "si";
public:
    CreateDefsHandler(std::vector<std::string>& inCommand);
    virtual ~CreateDefsHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
