// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "GetValueHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CGetValueHandler::CGetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CGetValueHandler::getProperAmountOfArgs() const noexcept
{
    return 3;
}

std::string CGetValueHandler::getProperTypesOfArgs() const noexcept
{
    return "sii";
}

CODE CGetValueHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::GOAL_ID]);
    int idOfNewVal = std::stoi(receivedIdOfNewVal);

    TableOfTables* cache = std::get<0>(pairedShapeCach);

    if (!isProperIdx(idxOrAmount, cache->getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }

    if (!std::get<1>(pairedShapeCach)[idxOrAmount])
    {
        return returnResultCode(CODE::UNDEFINED_OBJECT);
    }

    if (!isProperIdx(idOfNewVal, cache->getVal(idxOrAmount).getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }

    logger << std::to_string(cache->getVal(idxOrAmount).getVal(idOfNewVal)) << POST_PRINT;

    return CODE::SEEMS_LEGIT;
}
