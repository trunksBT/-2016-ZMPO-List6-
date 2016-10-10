#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class SetNameHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 3;
public:
    SetNameHandler(std::vector<std::string>& inCommand);
    virtual ~SetNameHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
};
