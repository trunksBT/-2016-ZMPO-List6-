#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CClearHandler final : public IHandler
{
public:
    CClearHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
