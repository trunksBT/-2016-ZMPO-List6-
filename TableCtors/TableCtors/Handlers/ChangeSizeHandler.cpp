#include "stdafx.h"
#include <iostream>

#include "ChangeSizeHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

ChangeSizeHandler::ChangeSizeHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE ChangeSizeHandler::performOn(std::vector<CTable*>& inCache)
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

void ChangeSizeHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedSourceId(wholeCommand_[idxOf::idOfCTable]);
    int sourceId = std::stoi(receivedSourceId);
    std::string receivedNewSize(wholeCommand_[idxOf::newSize]);
    int newSize = std::stoi(receivedNewSize);

    if(isProperIdx(sourceId, inCache))
    {
        if(newSize > MINUS_ONE)
        {
            if(inCache[sourceId] == nullptr)
            {
                inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
                if(flag::printOn)
                {
                    std::cout << toString(inResultCode);
                }
            }
            else
            {
                inCache[sourceId]->changeSize(newSize);
            }
        }
        else
        {
            inResultCode = ERROR_CODE::WRONG_VALUE;
            if(flag::printOn)
            {
                std::cout << toString(inResultCode);
            }
        }
    }
    else
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::printOn)
        {
            std::cout << toString(inResultCode);
        }
    }
}

ChangeSizeHandler::~ChangeSizeHandler()
{}
