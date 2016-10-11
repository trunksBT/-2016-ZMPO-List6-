#include "stdafx.h"
#include <iostream>

#include "SetValueHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CSetValueHandler::CSetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CSetValueHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS_))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS_))
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

void CSetValueHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::GOAL_ID]);
    int idOfNewVal = std::stoi(receivedIdOfNewVal);
    std::string receivedNewVal(wholeCommand_[idxOf::NEW_VAL]);
    int newVal = std::stoi(receivedNewVal);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            if(isProperIdx(idOfNewVal, retTable->getSize()))
            {
                retTable->setVal(idOfNewVal, newVal);
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
        else
        {
            inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
            if(flag::PRINT_ON)
            {
                std::cout << toString(inResultCode);
            }
        }
        retTable = nullptr;
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

CSetValueHandler::~CSetValueHandler()
{}

