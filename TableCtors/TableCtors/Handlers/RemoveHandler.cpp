#include "stdafx.h"
#include <iostream>

#include "RemoveHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

RemoveHandler::RemoveHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void RemoveHandler::perform(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount > inCache.size() || idxOrAmount > inCache.size() < 0)
    {
        std::cout << indexOutOfBound << POST_PRINT;
    }
    else
    {
        std::cout << INDENT << messageLiterals::remove << SEPARATOR;
        {
            CTable* retTable = inCache.at(idxOrAmount);
            if(retTable != nullptr)
            {
                std::cout << retTable->getName() << POST_PRINT;
            }
            delete retTable;
            inCache.at(idxOrAmount) = nullptr;
        }
    }
}

RemoveHandler::~RemoveHandler()
{}
