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

const int CCreateDefsHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CCreateDefsHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CCreateDefsHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount <= ZERO)
    {
        return returnResultCode(ERROR_CODE::WRONG_VALUE);
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

    return ERROR_CODE::SEEMS_LEGIT;
}
