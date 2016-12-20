#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CGetNameHandler final : public IHandler
{
public:
    CGetNameHandler(std::vector<std::string>& inCommand);
protected:
    CODE performOn(InitializedCTable& pairedShapeCach) override;
    const int getProperAmountOfArgs() const noexcept override;
    std::string getProperTypesOfArgs() const noexcept override;
};
