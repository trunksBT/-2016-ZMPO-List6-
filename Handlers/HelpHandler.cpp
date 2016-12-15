// Copyrights TrunkBT_KorytkoBT
#include <iostream>

#include "HelpHandler.h"
#include <Utils/Utils.hpp>
#include <ElementsAndTables/CTable.hpp>
#include <Flyweight/Flyweight.h>

using namespace defaultVals;

using namespace funs;

CHelpHandler::CHelpHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CHelpHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CHelpHandler::getProperTypesOfArgs()
{
    return "s";
}

ERROR_CODE CHelpHandler::performOn(std::vector<CTable*>& inCache)
{
    for(int i = 0; i < fullCommands::allCommands.size(); i++)
    {
        std::cout << fullCommands::allCommands[i] << POST_PRINT;
    }

    return ERROR_CODE::SEEMS_LEGIT;
}
