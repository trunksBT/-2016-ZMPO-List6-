#include "stdafx.h"
#include <iostream>

#include "PrintAllHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CPrintAllHandler::CPrintAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CPrintAllHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CPrintAllHandler::getProperTypesOfArgs()
{
    return "s";
}

ERROR_CODE CPrintAllHandler::performOn(std::vector<CTable*>& inCache)
{
    if(inCache.size() == 0)
    {
        return returnResultCode(ERROR_CODE::UNDEFINED_OBJECT);
    }
    else
    {
        for(int i = 0; i < inCache.size(); i++)
        {
            std::cout << i << SEPARATOR;

            if(inCache[i] == nullptr)
            {
                std::cout << toString(ERROR_CODE::UNDEFINED_OBJECT);
            }
            else
            {
                std::cout << inCache[i]->toString();
            }

            std::cout << POST_PRINT;
        }
    }

    return ERROR_CODE::SEEMS_LEGIT;
}
