#pragma once

#include <vector>
#include <string>

#include <Handlers/IHandler.h>

class CCreateCopyHandler final : public IHandler
{
public:
    CCreateCopyHandler(std::vector<std::string>& inCommand);
protected:
    CODE performOn(InitializedCTable& pairedShapeCach) override;
    const int getProperAmountOfArgs() const noexcept override;
    std::string getProperTypesOfArgs() const noexcept override;
};
