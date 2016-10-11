#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CChangeSizeHandler final : public IHandler
{
public:
    CChangeSizeHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
