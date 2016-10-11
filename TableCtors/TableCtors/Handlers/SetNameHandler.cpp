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

const int CSetNameHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CSetNameHandler::getProperTypesOfArgs()
{
    return "sis";
}

ERROR_CODE CSetNameHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string newName(wholeCommand_[idxOf::NEW_NAME]);
    std::string receivedId(std::move(wholeCommand_[idxOf::AMOUNT]));
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache[idxOrAmount] == nullptr)
        {
            return returnResultCode(ERROR_CODE::UNDEFINED_OBJECT);
        }
        else
        {
            inCache[idxOrAmount]->setName(newName);
        }
    }
    else
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }

    return ERROR_CODE::SEEMS_LEGIT;
}
