#include "stdafx.h"
#include <iostream>

#include "CreateDefHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace funs;

CCreateDefHandler::CCreateDefHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CCreateDefHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CCreateDefHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CCreateDefHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);

    int idxOrAmount = std::stoi(receivedId);
    if(!isProperIdx(idxOrAmount, inCache))
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }

    if(inCache[idxOrAmount] != nullptr)
    {
        delete inCache[idxOrAmount];
    }
    inCache[idxOrAmount] = CTable::buildNewObj();

    return ERROR_CODE::SEEMS_LEGIT;
}
