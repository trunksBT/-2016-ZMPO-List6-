#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CGetSizeHandler final : public IHandler
{
public:
    CGetSizeHandler(std::vector<std::string>& inCommand);
protected:
    CODE performOn(InitializedCTable& pairedShapeCach) override;
    const int getProperAmountOfArgs() const noexcept override;
    std::string getProperTypesOfArgs() const noexcept override;
};
