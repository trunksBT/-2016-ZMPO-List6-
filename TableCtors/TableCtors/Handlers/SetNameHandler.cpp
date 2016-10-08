#include "stdafx.h"
#include <iostream>

#include "SetNameHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

SetNameHandler::SetNameHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void SetNameHandler::perform(std::vector<CTable*>& inCache)
{
    std::string newName(wholeCommand_[idxOf::newName]);
    std::string receivedId(std::move(wholeCommand_[idxOf::amount]));
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount > inCache.size() || idxOrAmount > inCache.size() < 0)
    {
        std::cout << indexOutOfBound << POST_PRINT;
    }
    else if(inCache[idxOrAmount] == nullptr)
    {
        std::cout << undefinedObject << POST_PRINT;
    }
    else
    {
        std::cout << INDENT << messageLiterals::setName << POST_PRINT;
        {
            inCache[idxOrAmount]->setName(newName);
        }
    }
}

SetNameHandler::~SetNameHandler()
{}
