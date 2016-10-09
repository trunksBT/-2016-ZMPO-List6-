#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class PrintHandler final : public IHandler
{
public:
    PrintHandler(std::vector<std::string>& inCommand);
    virtual ~PrintHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
};
