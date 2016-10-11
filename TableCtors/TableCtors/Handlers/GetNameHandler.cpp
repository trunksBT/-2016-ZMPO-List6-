#include "stdafx.h"
#include <iostream>

#include "GetNameHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CGetNameHandler::CGetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CGetNameHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CGetNameHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CGetNameHandler::performOn(std::vector<CTable*>& inCache)
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
