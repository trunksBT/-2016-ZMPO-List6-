#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class SetValueHandler final : public IHandler
{
public:
    SetValueHandler(std::vector<std::string>& inCommand);
    virtual ~SetValueHandler();
    ERROR_CODE perform(std::vector<CTable*>& inFlyweightCache) override;
};
