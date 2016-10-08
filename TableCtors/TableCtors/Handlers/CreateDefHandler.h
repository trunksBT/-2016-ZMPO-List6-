#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateDefHandler final : public IHandler
{
public:
    CreateDefHandler(std::vector<std::string>& inCommand);
    virtual ~CreateDefHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
