#include "stdafx.h"
#include <iostream>

#include "SetNameHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

SetNameHandler::SetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    performOn(Flyweight::cache_);
}

ERROR_CODE SetNameHandler::performOn(std::vector<CTable*>& inCache)
{
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }
    std::string newName(wholeCommand_[idxOf::newName]);
    std::string receivedId(std::move(wholeCommand_[idxOf::amount]));
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache[idxOrAmount] == nullptr)
        {
            std::cout << undefinedObject;
        }
        else
        {
            inCache[idxOrAmount]->setName(newName);
        }
    }
    else
    {
        if(flag::printOn)
        {
            std::cout << indexOutOfBound;
        }
    }
    return ERROR_CODE::NOT_HANDLED_ERROR_REPORTING;
}

SetNameHandler::~SetNameHandler()
{
}
