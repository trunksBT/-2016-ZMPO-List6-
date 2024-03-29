// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "ClearHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CClearHandler::CClearHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CClearHandler::getProperAmountOfArgs() const noexcept
{
    return 2;
}

std::string CClearHandler::getProperTypesOfArgs() const noexcept
{
    return "si";
}

CODE CClearHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int idxOrAmount = std::stoi(receivedId);

    try
    {
        if (!std::get<1>(pairedShapeCach)[idxOrAmount])
        {
            return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
        }

        for (int i = 0; i < std::get<0>(pairedShapeCach)->getVal(idxOrAmount).getSize(); i++)
        {
            std::get<0>(pairedShapeCach)->getVal(idxOrAmount).getVal(i) = ZERO;
        }
    }
    catch (...)
    {
        logger << EXCEPTION << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}
