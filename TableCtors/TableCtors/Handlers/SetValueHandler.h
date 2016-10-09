#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class SetValueHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 4;
public:
    SetValueHandler(std::vector<std::string>& inCommand);
    virtual ~SetValueHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
};
