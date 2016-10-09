#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class SetValueHandler final : public IHandler
{
public:
    SetValueHandler(std::vector<std::string>& inCommand);
    virtual ~SetValueHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
