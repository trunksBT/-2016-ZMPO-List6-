#include "stdafx.h"
#include <iostream>

#include "ClearHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CClearHandler::CClearHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CClearHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CClearHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CClearHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int idxOrAmount = std::stoi(receivedId);
    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache.at(idxOrAmount) != nullptr)
        {
            inCache.at(idxOrAmount)->initTable();
        }
    }
    else
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }

    return ERROR_CODE::SEEMS_LEGIT;
}
