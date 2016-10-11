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

const int CSetValueHandler::getProperAmountOfArgs()
{
    return 4;
}

std::string CSetValueHandler::getProperTypesOfArgs()
{
    return "siii";
}

ERROR_CODE CSetValueHandler::performOn(std::vector<CTable*>& inCache)
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
