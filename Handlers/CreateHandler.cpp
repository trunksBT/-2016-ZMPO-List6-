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

    try
    {
        std::get<0>(pairedShapeCach)->setVal(
            idxOrAmount,
            CTable<int>::buildNewObjRef(newSize, initialName));
    }
    catch (...)
    {
        logger << EXCEPTION << POST_PRINT;
        return CODE::WRONG_VALUE;
    }

    return CODE::SEEMS_LEGIT;
}
