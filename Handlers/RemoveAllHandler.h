#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CRemoveAllHandler final : public IHandler
{
public:
    CRemoveAllHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
