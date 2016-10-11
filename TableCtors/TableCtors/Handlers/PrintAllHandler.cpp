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

ERROR_CODE CPrintAllHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS))
        {
            performOnProperArgs(inCache, resultCode);
        }
        else
        {
            resultCode = ERROR_CODE::ERROR_ARGS_PARSING;
            if(flag::PRINT_ON)
            {
                std::cout << toString(resultCode);
            }
        }
    }
    else
    {
        resultCode = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
        if(flag::PRINT_ON)
        {
            std::cout << toString(resultCode);
        }
    }

    return resultCode;
}

void CPrintAllHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    if(inCache.size() == 0)
    {
        inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
        if(flag::PRINT_ON)
        {
            std::cout << toString(inResultCode);
        }
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
}
CPrintAllHandler::~CPrintAllHandler()
{}
