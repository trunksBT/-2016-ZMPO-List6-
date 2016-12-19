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
    if (!isCacheInitialized(pairedShapeCach))
    {
        return CODE::SEEMS_LEGIT;
    }

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
                logger << NOT_INITIALIZED_TABLE;
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

bool CPrintAllHandler::isCacheInitialized(InitializedCTable & pairedShapeCach)
{
    std::map<int, bool>& isInitialized = std::get<1>(pairedShapeCach);
    bool isCacheInitialized = false;
    for (int i = 0; i < isInitialized.size(); i++)
    {
        isCacheInitialized |= isInitialized[i];
    }
    return isCacheInitialized;
}
