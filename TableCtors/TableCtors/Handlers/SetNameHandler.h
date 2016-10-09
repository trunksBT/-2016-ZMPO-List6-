#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class SetNameHandler final : public IHandler
{
public:
    SetNameHandler(std::vector<std::string>& inCommand);
    virtual ~SetNameHandler();
    ERROR_CODE perform(std::vector<CTable*>& inFlyweightCache) override;
};
