// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "ChangeSizeHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CChangeSizeHandler::CChangeSizeHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CChangeSizeHandler::getProperAmountOfArgs() const noexcept
{
    return 3;
}

std::string CChangeSizeHandler::getProperTypesOfArgs() const noexcept
{
    return "sii";
}

CODE CChangeSizeHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
    int newSize = std::stoi(receivedNewSize);

    if (newSize < 0 || !isProperIdx(idxOrAmount, std::get<0>(pairedShapeCach)->getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }

    if (newSize > 0)
    {
        std::get<0>(pairedShapeCach)->getVal(idxOrAmount).setSize(newSize);
    }

    return CODE::SEEMS_LEGIT;
}

