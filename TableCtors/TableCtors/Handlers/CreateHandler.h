#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 4;
    std::string PROPER_TYPES_OF_ARGS = "siis";
public:
    CreateHandler(std::vector<std::string>& inCommand);
    virtual ~CreateHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
