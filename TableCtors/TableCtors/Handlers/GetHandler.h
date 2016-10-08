#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class GetHandler final : public IHandler
{
public:
    GetHandler(std::vector<std::string>& inCommand);
    virtual ~GetHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
