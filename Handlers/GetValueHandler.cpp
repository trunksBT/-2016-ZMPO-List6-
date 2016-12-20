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

    try
    {
        if (!std::get<1>(pairedShapeCach)[idxOrAmount])
        {
            return returnResultCode(CODE::UNDEFINED_OBJECT);
        }

        logger << std::to_string(std::get<0>(pairedShapeCach)->
            getVal(idxOrAmount).getVal(idOfNewVal)) << POST_PRINT;
    }
    catch (...)
    {
        logger << "EXCEPTION" << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}
