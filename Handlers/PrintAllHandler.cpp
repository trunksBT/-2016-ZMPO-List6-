// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "PrintAllHandler.hpp"
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>

using namespace defaultVals;
using namespace funs;

CPrintAllHandler::CPrintAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CPrintAllHandler::getProperAmountOfArgs() const noexcept
{
    return 1;
}

std::string CPrintAllHandler::getProperTypesOfArgs() const noexcept
{
    return "s";
}

CODE CPrintAllHandler::performOn(InitializedCTable& pairedShapeCach)
{
    bool isCacheInitialized = false;
    for (int i = 0; i < std::get<1>(pairedShapeCach).size(); i++)
    {
        isCacheInitialized =
            (isCacheInitialized || std::get<1>(pairedShapeCach).at(i));
    }
    if (!isCacheInitialized)
    {
        return CODE::UNDEFINED_OBJECT;
    }

    if(std::get<0>(pairedShapeCach)->getSize() == 0)
    {
        return returnResultCode(CODE::UNDEFINED_OBJECT);
    }
    else
    {
        for(int i = 0; i < std::get<0>(pairedShapeCach)->getSize(); i++)
        {
            if(!std::get<1>(pairedShapeCach)[i])
            {
                logger << NOT_INITIALIZED_TABLE;
            }
            else
            {
                logger << static_cast<std::string>(std::get<0>(pairedShapeCach)->getVal(i));
            }
        }

        std::cout << POST_PRINT;
    }

    return CODE::SEEMS_LEGIT;
}
