// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "GoHandler.hpp"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;
using namespace funs;

CGoHandler::CGoHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CGoHandler::getProperAmountOfArgs() const noexcept
{
    return 2;
}

std::string CGoHandler::getProperTypesOfArgs() const noexcept
{
    return "si";
}

CODE CGoHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    try
    {
        if (std::get<idxOf::CACHE>(pairedShapeCach) != nullptr)
        {
            delete std::get<idxOf::CACHE>(pairedShapeCach);
        }

        std::get<idxOf::CACHE>(pairedShapeCach) = CTable<CTable<int>>::buildNewObj(idxOrAmount);

        for (int i = 0; i < idxOrAmount; i++)
        {
            std::get<idxOf::IS_INITIALIZED>(pairedShapeCach)[i] = true;
        }
    }
    catch (OwnException& e)
    {
        logger << e.what() << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}
