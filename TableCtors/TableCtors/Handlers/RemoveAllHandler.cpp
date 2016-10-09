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
}

ERROR_CODE RemoveAllHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << messageLiterals::removeAll << POST_PRINT;
    }
    return resultCode;
}

RemoveAllHandler::~RemoveAllHandler()
{
    Flyweight::releaseResources();
}
