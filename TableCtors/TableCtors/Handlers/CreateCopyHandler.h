#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CCreateCopyHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS_ = 3;
    std::string PROPER_TYPES_OF_ARGS_ = "sii";
public:
    CCreateCopyHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateCopyHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    void performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode);
};
