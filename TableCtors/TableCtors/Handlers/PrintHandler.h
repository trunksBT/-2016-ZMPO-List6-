#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class PrintHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 2;
public:
    PrintHandler(std::vector<std::string>& inCommand);
    virtual ~PrintHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
