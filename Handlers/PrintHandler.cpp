// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "PrintHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;

using namespace funs;

CPrintHandler::CPrintHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CPrintHandler::getProperAmountOfArgs() const noexcept
{
    return 2;
}

std::string CPrintHandler::getProperTypesOfArgs() const noexcept
{
    return "si";
}

CODE CPrintHandler::performOn(InitializedCTable& pairedShapeCach)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    TableOfTables* cache = std::get<0>(pairedShapeCach);
    if (cache->getSize() == 0 || !isProperIdx(idxOrAmount, std::get<0>(pairedShapeCach)->getSize()))
    {
        return returnResultCode(CODE::UNDEFINED_OBJECT);
    }
    else
    {
        if (!std::get<1>(pairedShapeCach)[idxOrAmount])
        {
            logger << NOT_INITIALIZED_TABLE;
        }
        else
        {
            logger << static_cast<std::string>(cache->getVal(idxOrAmount));
        }

        std::cout << POST_PRINT;
    }

    return CODE::SEEMS_LEGIT;
}
