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
    if(idxOrAmount <= ZERO)
    {
        return returnResultCode(CODE::WRONG_VALUE);
    }
    std::get<0>(pairedShapeCach) = new CTable<CTable<int>>(idxOrAmount);
    for (int i = 0; i < idxOrAmount; i++)
    {
        std::get<1>(pairedShapeCach)[i] = true;
    }
    //std::get<1>(inCache)

    //else
    //{
    //    if(idxOrAmount > inCache.size())
    //    {
    //        inCache.reserve(idxOrAmount);
    //    }
    //    int cacheSize = inCache.size();
    //    int cursorIdx = ZERO;
    //}

    return CODE::SEEMS_LEGIT;
}
