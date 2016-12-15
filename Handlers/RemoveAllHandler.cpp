// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "RemoveAllHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>
#include <Flyweight/Flyweight.h>

using namespace defaultVals;

using namespace funs;

CRemoveAllHandler::CRemoveAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CRemoveAllHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CRemoveAllHandler::getProperTypesOfArgs()
{
    return "s";
}

ERROR_CODE CRemoveAllHandler::performOn(std::vector<CTable*>& inCache)
{
    if(isVectorEmpty(inCache))
    {
        return returnResultCode(ERROR_CODE::UNDEFINED_OBJECT);
    }

    CFlyweight::releaseResources();

    return ERROR_CODE::SEEMS_LEGIT;
}
