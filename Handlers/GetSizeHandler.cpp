// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "GetSizeHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;
using namespace funs;

CGetSizeHandler::CGetSizeHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CGetSizeHandler::getProperAmountOfArgs() const noexcept
{
    return 2;
}

std::string CGetSizeHandler::getProperTypesOfArgs() const noexcept
{
    return "si";
}

CODE CGetSizeHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    if (!std::get<1>(pairedShapeCach)[idxOrAmount])
    {
        logger << NOT_INITIALIZED_TABLE;
    }
    else
    {
        logger << std::to_string(static_cast<int>(
            std::get<0>(pairedShapeCach)->getVal(idxOrAmount).getSize()));
    }

    std::cout << POST_PRINT;

    return CODE::SEEMS_LEGIT;
}
