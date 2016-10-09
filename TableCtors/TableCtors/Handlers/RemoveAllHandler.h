#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class RemoveAllHandler final : public IHandler
{
public:
    RemoveAllHandler(std::vector<std::string>& inCommand);
    virtual ~RemoveAllHandler();
    ERROR_CODE perform(std::vector<CTable*>& inFlyweightCache) override;
};
