#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class RemoveHandler final : public IHandler
{
public:
    RemoveHandler(std::vector<std::string>& inCommand);
    virtual ~RemoveHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
