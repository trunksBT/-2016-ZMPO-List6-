#include "stdafx.h"
#include <iostream>

#include "CreateDefsHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

CreateDefsHandler::CreateDefsHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CreateDefsHandler::performOn(std::vector<CTable*>& inCache)
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

void CreateDefsHandler::performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{

    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount < ZERO)
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
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

CreateDefsHandler::~CreateDefsHandler()
{}
