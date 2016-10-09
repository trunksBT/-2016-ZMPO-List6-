#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class GetNameHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS = 2;
public:
    GetNameHandler(std::vector<std::string>& inCommand);
    virtual ~GetNameHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
};
