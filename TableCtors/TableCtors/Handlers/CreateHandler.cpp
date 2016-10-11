#include "stdafx.h"
#include <iostream>

#include "CreateHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CCreateHandler::CCreateHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CCreateHandler::getProperAmountOfArgs()
{
    return 4;
}

std::string CCreateHandler::getProperTypesOfArgs()
{
    return "siis";
}

ERROR_CODE CCreateHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
    int newSize = std::stoi(receivedNewSize);
    std::string initialName(wholeCommand_[idxOf::INITIAL_NAME]);

    if(idxOrAmount < 0)
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }
    else
    {
        if(newSize > 0)
        {
            if(idxOrAmount > inCache.size())
            {
                inCache.resize(idxOrAmount + ONE);
            }
            if(inCache[idxOrAmount] != nullptr)
            {
                delete inCache[idxOrAmount];
            }
            inCache[idxOrAmount] = CTable::buildNewObj(newSize, initialName);
        }
        else
        {
            return returnResultCode(ERROR_CODE::WRONG_VALUE);
        }
    }

    return ERROR_CODE::SEEMS_LEGIT;
}
