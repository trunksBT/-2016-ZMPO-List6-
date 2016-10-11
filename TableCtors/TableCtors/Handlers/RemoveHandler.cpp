#include "stdafx.h"
#include <iostream>

#include "RemoveHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CRemoveHandler::CRemoveHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CRemoveHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CRemoveHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CRemoveHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            std::cout << retTable->getName();
        }
        delete retTable;
        inCache.at(idxOrAmount) = nullptr;
    }
    else
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }
    
    return ERROR_CODE::SEEMS_LEGIT;
}
