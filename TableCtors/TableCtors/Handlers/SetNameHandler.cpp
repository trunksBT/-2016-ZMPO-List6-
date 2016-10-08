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
    perform(Flyweight::cache_);
}

void SetNameHandler::perform(std::vector<CTable*>& inCache)
{
    std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

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
        std::cout << indexOutOfBound;
    }
}

SetNameHandler::~SetNameHandler()
{
}
