#include "stdafx.h"
#include <iostream>

#include "RemoveAllHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

RemoveAllHandler::RemoveAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

ERROR_CODE RemoveAllHandler::perform(std::vector<CTable*>& inCache)
{
    if(flag::printOn)
    {
        std::cout << messageLiterals::removeAll << POST_PRINT;
    }
    return ERROR_CODE::NOT_HANDLED_ERROR_REPORTING;
}

RemoveAllHandler::~RemoveAllHandler()
{
    Flyweight::releaseResources();
}
