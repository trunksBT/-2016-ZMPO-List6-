#include "stdafx.h"
#include <iostream>

#include "GetSizeHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

GetSizeHandler::GetSizeHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void GetSizeHandler::perform(std::vector<CTable*>& inCache)
{
    std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            std::cout << retTable->getSize();
        }
        else
        {
            std::cout << undefinedObject;
        }
        retTable == nullptr;
    }
    else
    {
        std::cout << indexOutOfBound;
    }
}

GetSizeHandler::~GetSizeHandler()
{}

