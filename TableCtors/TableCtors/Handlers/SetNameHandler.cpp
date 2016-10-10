#include "stdafx.h"
#include <iostream>

#include "SetNameHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

SetNameHandler::SetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE SetNameHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
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

void SetNameHandler::performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string newName(wholeCommand_[idxOf::newName]);
    std::string receivedId(std::move(wholeCommand_[idxOf::amount]));
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache[idxOrAmount] == nullptr)
        {
            inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
            if(flag::printOn)
            {
                std::cout << toString(inResultCode);
            }
        }
        else
        {
            inCache[idxOrAmount]->setName(newName);
        }
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

SetNameHandler::~SetNameHandler()
{
}
