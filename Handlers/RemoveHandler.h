#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CRemoveHandler final : public IHandler
{
public:
    CRemoveHandler(std::vector<std::string>& inCommand);
protected:
    CODE performOn(InitializedCTable& pairedShapeCach) override;
    const int getProperAmountOfArgs() const noexcept override;
    std::string getProperTypesOfArgs() const noexcept override;
};
