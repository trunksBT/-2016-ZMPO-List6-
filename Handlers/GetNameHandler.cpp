// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "GetNameHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;
using namespace funs;

CGetNameHandler::CGetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CGetNameHandler::getProperAmountOfArgs() const noexcept
{
    return 2;
}

std::string CGetNameHandler::getProperTypesOfArgs() const noexcept
{
    return "si";
}

CODE CGetNameHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    TableOfTables* cache = std::get<0>(pairedShapeCach);
    if (cache->getSize() == 0 || !isProperIdx(idxOrAmount, std::get<0>(pairedShapeCach)->getSize()))
    {
        return returnResultCode(CODE::UNDEFINED_OBJECT);
    }

    if (!std::get<1>(pairedShapeCach)[idxOrAmount])
    {
        logger << NOT_INITIALIZED_TABLE;
    }
    else
    {
        logger << cache->getVal(idxOrAmount).getName();
    }

    std::cout << POST_PRINT;

    return CODE::SEEMS_LEGIT;
}
