#include "stdafx.h"
#include <iostream>

#include "CreateDefHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

CreateDefHandler::CreateDefHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CreateDefHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }

    bool isProperAmountOfArgs = true;
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

void CreateDefHandler::performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedId(wholeCommand_[idxOf::idOfCTable]);
    int idxOrAmount = std::stoi(receivedId);
    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache[idxOrAmount] != nullptr)
        {
            delete inCache[idxOrAmount];
        }
        inCache[idxOrAmount] = CTable::buildNewObj();
    }
    else
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::printOn)
        {
            std::cout << toString(inResultCode);
        }
    }
}

CreateDefHandler::~CreateDefHandler()
{
}
