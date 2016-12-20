#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CClearHandler final : public IHandler
{
public:
    CClearHandler(std::vector<std::string>& inCommand);
protected:
    CODE performOn(InitializedCTable& pairedShapeCach) override;
    const int getProperAmountOfArgs() const noexcept override;
    std::string getProperTypesOfArgs() const noexcept override;
};
