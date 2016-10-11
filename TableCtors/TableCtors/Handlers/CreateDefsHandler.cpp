#include "stdafx.h"
#include <iostream>

#include "CreateDefsHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CCreateDefsHandler::CCreateDefsHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CCreateDefsHandler::performOn(std::vector<CTable*>& inCache)
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

void CCreateDefsHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount <= ZERO)
    {
        inResultCode = ERROR_CODE::WRONG_VALUE;
        if(flag::printOn)
        {
            std::cout << toString(inResultCode);
        }
    }
    else
    {
        if(idxOrAmount > inCache.size())
        {
            inCache.reserve(idxOrAmount);
        }
        int cacheSize = inCache.size();
        int cursorIdx = ZERO;
        for(int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount;)
        {
            if(cursorIdx < inCache.size())
            {
                if(inCache[cursorIdx] == nullptr)
                {
                    inCache[cursorIdx] = CTable::buildNewObj();
                    ammountOfCreatedObj++;
                }
            }
            else
            {
                inCache.emplace_back(CTable::buildNewObj());
                ammountOfCreatedObj++;
            }
            cursorIdx++;
        }
    }
}

CCreateDefsHandler::~CCreateDefsHandler()
{}
