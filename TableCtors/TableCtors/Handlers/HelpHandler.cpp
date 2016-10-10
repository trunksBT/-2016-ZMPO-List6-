#include "stdafx.h"
#include <iostream>

#include "HelpHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

HelpHandler::HelpHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE HelpHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS))
        {
            performOnProperArgs(inCache, resultCode);
        }
        else
        {
            resultCode = ERROR_CODE::ERROR_ARGS_PARSING;
            if(flag::printOn)
            {
                std::cout << toString(resultCode);
            }
        }
    }
    else
    {
        resultCode = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
        if(flag::printOn)
        {
            std::cout << toString(resultCode);
        }
    }

    return resultCode;
}

void HelpHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    for(int i = 0; i < fullCommands::allCommands.size(); i++)
    {
        std::cout << fullCommands::allCommands[i] << POST_PRINT;
    }
}

HelpHandler::~HelpHandler()
{}

