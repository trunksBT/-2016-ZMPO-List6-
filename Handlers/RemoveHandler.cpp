// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "RemoveHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CRemoveHandler::CRemoveHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CRemoveHandler::getProperAmountOfArgs() const noexcept
{
    return 2;
}

std::string CRemoveHandler::getProperTypesOfArgs() const noexcept
{
    return "si";
}

CODE CRemoveHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    if(!isProperIdx(idxOrAmount, std::get<0>(pairedShapeCach)->getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }
    else
    {
        std::get<1>(pairedShapeCach)[idxOrAmount] = false;
    }
    
    return CODE::SEEMS_LEGIT;
}
