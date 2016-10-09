#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateCopyHandler final : public IHandler
{
public:
    CreateCopyHandler(std::vector<std::string>& inCommand);
    virtual ~CreateCopyHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
