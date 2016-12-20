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

    std::map<int, bool>& isInitialized = std::get<1>(pairedShapeCach);

    try
    {
        if (!isInitialized[sourceId])
        {
            return returnResultCode(CODE::UNDEFINED_OBJECT);
        }

        if (destinyId == sourceId)
        {
            return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
        }

        CTable<int>& sourceTable = std::get<0>(pairedShapeCach)->getVal(sourceId);
        std::get<0>(pairedShapeCach)->setVal(
            destinyId,
            CTable<int>::buildNewObjRef(std::get<0>(pairedShapeCach)->getVal(sourceId)));
    }
    catch (...)
    {
        logger << EXCEPTION << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}
