// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "SetNameHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CSetNameHandler::CSetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CSetNameHandler::getProperAmountOfArgs() const noexcept
{
    return 3;
}

std::string CSetNameHandler::getProperTypesOfArgs() const noexcept
{
    return "sis";
}

CODE CSetNameHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(std::move(wholeCommand_[idxOf::AMOUNT]));
    int idxOrAmount = std::stoi(receivedId);
    std::string newName(wholeCommand_[idxOf::NEW_NAME]);

    if (!std::get<1>(pairedShapeCach)[idxOrAmount])
    {
        return CODE::WRONG_VALUE;
    }
    std::get<0>(pairedShapeCach)->getVal(idxOrAmount).setName(newName);

    return CODE::SEEMS_LEGIT;
}
