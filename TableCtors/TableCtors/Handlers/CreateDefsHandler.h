#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CreateDefsHandler final : public IHandler
{
public:
    CreateDefsHandler(std::vector<std::string>& inCommand);
    virtual ~CreateDefsHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
