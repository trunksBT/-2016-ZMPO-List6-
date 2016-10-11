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

ERROR_CODE CCreateDefHandler::performOn(std::vector<CTable*>& inCache)
{
    return checkAndPerform(inCache);
}

ERROR_CODE CCreateDefHandler::checkAndPerform(std::vector<CTable*>& inCache)
{
    if(!isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS_))
    {
        return returnResultCode(ERROR_CODE::WRONG_AMOUNT_OF_ARGS);
    }
    else if(!isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS_))
    {
        return returnResultCode(ERROR_CODE::ERROR_ARGS_PARSING);
    }
    else
    {
        return performOnProperArgs(inCache);
    }
}

ERROR_CODE CCreateDefHandler::performOnProperArgs(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);

    int idxOrAmount = std::stoi(receivedId);
    if(!isProperIdx(idxOrAmount, inCache))
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);;
    }

    if(inCache[idxOrAmount] != nullptr)
    {
        delete inCache[idxOrAmount];
    }
    inCache[idxOrAmount] = CTable::buildNewObj();

    return ERROR_CODE::SEEMS_LEGIT;
}

CCreateDefHandler::~CCreateDefHandler()
{
}
