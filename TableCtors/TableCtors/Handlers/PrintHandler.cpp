#include "stdafx.h"
#include <iostream>

#include "PrintHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CPrintHandler::CPrintHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CPrintHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CPrintHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CPrintHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            std::cout << retTable->toString();
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
