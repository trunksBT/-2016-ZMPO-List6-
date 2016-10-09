#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class PrintHandler final : public IHandler
{
public:
    PrintHandler(std::vector<std::string>& inCommand);
    virtual ~PrintHandler();
protected:
    void perform(std::vector<CTable*>& inFlyweightCache) override;
};
