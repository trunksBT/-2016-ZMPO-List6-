#include "stdafx.h"
#include <iostream>

#include "GetValueHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

GetValueHandler::GetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE GetValueHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS))
        {
            performOnProperArgs(inCache, resultCode);
        }
        else
        {
            resultCode = ERROR_CODE::ERROR_ARGS_PARSING;
            if(flag::printOn)
            {
                std::cout << toString(resultCode);
            }
        }
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

void GetValueHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::goalId]);
    int idOfNewVal = std::stoi(receivedIdOfNewVal);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            if(isProperIdx(idOfNewVal, retTable->getSize()))
            {
                std::cout << retTable->getVal(idOfNewVal);
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
        else
        {
            inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
            if(flag::printOn)
            {
                std::cout << toString(inResultCode);
            }
        }
        retTable = nullptr;
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

GetValueHandler::~GetValueHandler()
{}