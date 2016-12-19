// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "CreateHandler.hpp"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CCreateHandler::CCreateHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CCreateHandler::getProperAmountOfArgs() const noexcept
{
    return 4;
}

std::string CCreateHandler::getProperTypesOfArgs() const noexcept
{
    return "siis";
}

CODE CCreateHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
    int newSize = std::stoi(receivedNewSize);
    std::string initialName(wholeCommand_[idxOf::INITIAL_NAME]);
    
    if(newSize < 0 || !isProperIdx(idxOrAmount, std::get<0>(pairedShapeCach)->getSize()))
    {
        return returnResultCode(CODE::INDEX_OUT_OF_BOUNDS);
    }

    if(newSize > 0)
    {
        std::get<0>(pairedShapeCach)->setVal(
            idxOrAmount,
            CTable<int>(newSize, initialName));
    }

    return CODE::SEEMS_LEGIT;
}
