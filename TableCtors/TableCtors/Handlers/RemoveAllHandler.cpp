#include "stdafx.h"
#include <iostream>

#include "RemoveAllHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

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

    if(isProperArguments(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        performOnProperAmountOfArgs(inCache, resultCode);
    }
    else
    {
        resultCode = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
        if(flag::printOn)
        {
            std::cout << toString(resultCode);
        }
    }

    return resultCode;
}

void RemoveAllHandler::performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
}
RemoveAllHandler::~RemoveAllHandler()
{
    Flyweight::releaseResources();
}
