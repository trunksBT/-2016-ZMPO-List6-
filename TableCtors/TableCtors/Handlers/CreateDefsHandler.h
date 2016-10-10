#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateDefsHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 2;
public:
    CreateDefsHandler(std::vector<std::string>& inCommand);
    virtual ~CreateDefsHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
};
