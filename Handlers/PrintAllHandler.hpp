#pragma once

#include <vector>
#include <string>

#include <Handlers/IHandler.h>

class CPrintAllHandler final : public IHandler
{
public:
    CPrintAllHandler(std::vector<std::string>& inCommand);
protected:
    CODE performOn(InitializedCTable& pairedShapeCach) override;
    const int getProperAmountOfArgs() const noexcept override;
    std::string getProperTypesOfArgs() const noexcept override;
private:
    bool isCacheInitialized(InitializedCTable & pairedShapeCach);
};
