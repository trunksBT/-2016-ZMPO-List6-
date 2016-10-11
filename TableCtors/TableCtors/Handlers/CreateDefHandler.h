#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CCreateDefHandler final : public IHandler
{
private:
    const int PROPER_AMOUNT_OF_ARGS_ = 2;
    std::string PROPER_TYPES_OF_ARGS_ = "si";
public:
    CCreateDefHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateDefHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inCache) override;
    ERROR_CODE checkAndPerform(std::vector<CTable *> & inCache);
    ERROR_CODE CCreateDefHandler::performOnProperArgs(std::vector<CTable*>& inCache);
};
