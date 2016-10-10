#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class RemoveHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 2;
public:
    RemoveHandler(std::vector<std::string>& inCommand);
    virtual ~RemoveHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
