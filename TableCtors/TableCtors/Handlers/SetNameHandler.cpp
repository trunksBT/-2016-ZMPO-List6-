#include "stdafx.h"
#include <iostream>

#include "SetNameHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CSetNameHandler::CSetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CSetNameHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS))
        {
            performOnProperArgs(inCache, resultCode);
        }
        else
        {
            resultCode = ERROR_CODE::ERROR_ARGS_PARSING;
            if(flag::PRINT_ON)
            {
                std::cout << toString(resultCode);
            }
        }
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

void CSetNameHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string newName(wholeCommand_[idxOf::NEW_NAME]);
    std::string receivedId(std::move(wholeCommand_[idxOf::AMOUNT]));
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache[idxOrAmount] == nullptr)
        {
            inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
            if(flag::PRINT_ON)
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
        if(flag::PRINT_ON)
        {
            std::cout << toString(inResultCode);
        }
    }
}

CSetNameHandler::~CSetNameHandler()
{
}
