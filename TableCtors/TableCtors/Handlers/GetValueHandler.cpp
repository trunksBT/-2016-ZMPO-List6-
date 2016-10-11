#include "stdafx.h"
#include <iostream>

#include "GetValueHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CGetValueHandler::CGetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CGetValueHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CGetValueHandler::getProperTypesOfArgs()
{
    return "sii";
}

ERROR_CODE CGetValueHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::GOAL_ID]);
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
                return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
            }
        }
        else
        {
            return returnResultCode(ERROR_CODE::UNDEFINED_OBJECT);
        }
        retTable = nullptr;
    }
    else
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }

    return ERROR_CODE::SEEMS_LEGIT;
}
