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

    if(isProperArguments(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        performOnProperAmountOfArgs(inCache, resultCode);
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

void CreateCopyHandler::performOnProperAmountOfArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedSourceId(wholeCommand_[idxOf::idOfCTable]);
    int sourceId = std::stoi(receivedSourceId);
    std::string receivedDestinyId(wholeCommand_[idxOf::goalId]);
    int destinyId = std::stoi(receivedDestinyId);

    if(isProperIdx(sourceId, inCache))
    {
        CTable* copiedObj = new CTable(*inCache[sourceId]);
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
}

CreateCopyHandler::~CreateCopyHandler()
{}
