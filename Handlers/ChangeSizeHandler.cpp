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

    try
    {
        if (std::get<1>(pairedShapeCach)[idxOrAmount])
        {
            std::get<0>(pairedShapeCach)->getVal(idxOrAmount).setSize(newSize);
        }
        else
        {
            logger << toString(CODE::INDEX_OUT_OF_BOUNDS) << POST_PRINT;
        }
    }
    catch (...)
    {
        logger << EXCEPTION << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}

