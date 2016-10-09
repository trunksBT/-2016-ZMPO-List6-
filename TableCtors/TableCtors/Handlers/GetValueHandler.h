#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class GetValueHandler final : public IHandler
{
public:
    GetValueHandler(std::vector<std::string>& inCommand);
    virtual ~GetValueHandler();
    ERROR_CODE perform(std::vector<CTable*>& inFlyweightCache) override;
};
