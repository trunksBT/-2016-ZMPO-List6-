#include "stdafx.h"
#include <iostream>

#include "RemoveAllHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CRemoveAllHandler::CRemoveAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CRemoveAllHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        performOnProperArgs(inCache, resultCode);
    }
    else
    {
        resultCode = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
        if(flag::PRINT_ON)
        {
            std::cout << toString(resultCode);
        }
    }

    return resultCode;
}

void CRemoveAllHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    if(isVectorEmpty(inCache))
    {
        inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
        if(flag::PRINT_ON)
        {
            std::cout << toString(inResultCode);
        }
    }
}
CRemoveAllHandler::~CRemoveAllHandler()
{
    CFlyweight::releaseResources();
}
