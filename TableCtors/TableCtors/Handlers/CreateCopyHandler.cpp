#include "stdafx.h"
#include <iostream>

#include "CreateCopyHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

CreateCopyHandler::CreateCopyHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE CreateCopyHandler::performOn(std::vector<CTable*>& inCache)
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

void CreateCopyHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedSourceId(wholeCommand_[idxOf::idOfCTable]);
    int sourceId = std::stoi(receivedSourceId);
    std::string receivedDestinyId(wholeCommand_[idxOf::goalId]);
    int destinyId = std::stoi(receivedDestinyId);

    if(isProperIdx(sourceId, inCache))
    {
        if(inCache[sourceId] == nullptr)
        {
            inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
            if(flag::printOn)
            {
                std::cout << toString(inResultCode);
            }
        }
        else if(destinyId != sourceId)
        {
            CTable* copiedObj = CTable::buildNewObj(*inCache[sourceId]);
            bool isProperDestinyIdx = isProperIdx(destinyId, inCache);
            if(isProperDestinyIdx && inCache[destinyId] == nullptr)
            {
                inCache[destinyId] = copiedObj;
            }
            else if(isProperDestinyIdx && inCache[destinyId] != nullptr)
            {
                delete inCache[destinyId];
                inCache[destinyId] = copiedObj;
            }
            else
            {
                inCache.emplace_back(copiedObj);
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
    else
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::printOn)
        {
            std::cout << toString(inResultCode);
        }
    }
}

CreateCopyHandler::~CreateCopyHandler()
{}
