#include "stdafx.h"
#include <iostream>

#include "ChangeSizeHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CChangeSizeHandler::CChangeSizeHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CChangeSizeHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CChangeSizeHandler::getProperTypesOfArgs()
{
    return "sii";
}

ERROR_CODE CChangeSizeHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedSourceId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int sourceId = std::stoi(receivedSourceId);
    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
    int newSize = std::stoi(receivedNewSize);

    if(isProperIdx(sourceId, inCache))
    {
        if(newSize > MINUS_ONE)
        {
            if(inCache[sourceId] == nullptr)
            {
                return returnResultCode(ERROR_CODE::UNDEFINED_OBJECT);
            }
            else
            {
                inCache[sourceId]->setSize(newSize);
            }
        }
        else
        {
            return returnResultCode(ERROR_CODE::WRONG_VALUE);
        }
    }
    else
    {
        return returnResultCode(ERROR_CODE::INDEX_OUT_OF_BOUNDS);
    }

    return ERROR_CODE::SEEMS_LEGIT;
}

