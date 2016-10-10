#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateDefHandler final : public IHandler
{
public:
    CreateDefHandler(std::vector<std::string>& inCommand);
    virtual ~CreateDefHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
