// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "SetValueHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CSetValueHandler::CSetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CSetValueHandler::getProperAmountOfArgs() const noexcept
{
    return 4;
}

std::string CSetValueHandler::getProperTypesOfArgs() const noexcept
{
    return "siii";
}

CODE CSetValueHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::GOAL_ID]);
    int idOfNewVal = std::stoi(receivedIdOfNewVal);
    std::string receivedNewVal(wholeCommand_[idxOf::NEW_VAL]);
    int newVal = std::stoi(receivedNewVal);

    try
    {
        TableOfTables* cache = std::get<0>(pairedShapeCach);
        if (!std::get<1>(pairedShapeCach)[idxOrAmount])
        {
            return returnResultCode(CODE::UNDEFINED_OBJECT);
        }
        cache->getVal(idxOrAmount).setVal(idOfNewVal, newVal);
    }
    catch (...)
    {
        logger << EXCEPTION << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}
