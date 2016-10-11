#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CSetValueHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS_ = 4;
    std::string PROPER_TYPES_OF_ARGS_ = "siii";
public:
    CSetValueHandler(std::vector<std::string>& inCommand);
    virtual ~CSetValueHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
