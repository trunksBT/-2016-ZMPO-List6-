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
    TableOfTables* cache = std::get<0>(pairedShapeCach);
    if(cache->getSize() == 0)
    {
        return returnResultCode(CODE::UNDEFINED_OBJECT);
    }
    else
    {
        for(int i = 0; i < cache->getSize(); i++)
        {
            if(!std::get<1>(pairedShapeCach)[i])
            {
                std::cout << toString(CODE::UNDEFINED_OBJECT);
            }
            else
            {
                logger << static_cast<std::string>(cache->getVal(i));
            }
        }

        std::cout << POST_PRINT;
    }

    return CODE::SEEMS_LEGIT;
}
