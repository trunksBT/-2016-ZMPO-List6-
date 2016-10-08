#include "stdafx.h"
#include <iostream>

#include "CreateDefHandler.h"
#include "..\Utils.hpp"
#include "..\CTable.hpp"
#include "..\Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

CreateDefHandler::CreateDefHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void CreateDefHandler::perform(std::vector<CTable*>& inCache)
{
    std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

    std::string receivedId(wholeCommand_[idxOf::id]);
    int idxOrAmount = std::stoi(receivedId);
    if(isProperIdx(idxOrAmount, inCache))
    {
        if(inCache[idxOrAmount] != nullptr)
        {
            delete inCache[idxOrAmount];
        }
        inCache[idxOrAmount] = CTable::buildNewObj();
    }
    else
    {
        std::cout << undefinedObject;
    }
}

CreateDefHandler::~CreateDefHandler()
{
}
