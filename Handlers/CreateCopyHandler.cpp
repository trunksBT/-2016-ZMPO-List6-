// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "CreateCopyHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CCreateCopyHandler::CCreateCopyHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CCreateCopyHandler::getProperAmountOfArgs() const noexcept
{
    return 3;
}

std::string CCreateCopyHandler::getProperTypesOfArgs() const noexcept
{
    return "sii";
}

CODE CCreateCopyHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedDestinyId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int destinyId = std::stoi(receivedDestinyId);
    std::string receivedSourceId(wholeCommand_[idxOf::GOAL_ID]);
    int sourceId = std::stoi(receivedSourceId);

    TableOfTables* cache = std::get<0>(pairedShapeCach);
    std::map<int, bool>& isInitialized = std::get<1>(pairedShapeCach);

    if (!isProperIdx(sourceId, cache->getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }

    if(!isInitialized[sourceId])
    {
        return returnResultCode(CODE::UNDEFINED_OBJECT);
    }
    
    if (destinyId == sourceId || !isProperIdx(destinyId, cache->getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }

    CTable<int>& sourceTable = cache->getVal(sourceId);
    std::get<0>(pairedShapeCach)->setVal(
        destinyId,
        CTable<int>(sourceTable));

    return CODE::SEEMS_LEGIT;
}
