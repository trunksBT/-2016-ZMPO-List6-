#include "stdafx.h"
#include <iostream>

#include "CreateDefHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

CreateDefHandler::CreateDefHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void CreateDefHandler::perform(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::id]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount < inCache.size())
    {
        if(inCache[idxOrAmount] != nullptr)
        {
            delete inCache[idxOrAmount];
        }
        inCache[idxOrAmount] = CTable::buildNewObj();
    }
    else
    {
        std::cout << undefinedObject << POST_PRINT;
    }
}

CreateDefHandler::~CreateDefHandler()
{
}
