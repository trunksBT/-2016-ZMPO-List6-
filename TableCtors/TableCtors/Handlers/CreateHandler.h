#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CCreateHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS_ = 4;
    std::string PROPER_TYPES_OF_ARGS_ = "siis";
public:
    CCreateHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
