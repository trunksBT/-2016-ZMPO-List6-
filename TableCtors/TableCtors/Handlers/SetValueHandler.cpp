#include "stdafx.h"
#include <iostream>

#include "SetValueHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

SetValueHandler::SetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void SetValueHandler::perform(std::vector<CTable*>& inCache)
{
    std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::goalId]);
    int idOfNewVal = std::stoi(receivedIdOfNewVal);
    std::string receivedNewVal(wholeCommand_[idxOf::newVal]);
    int newVal = std::stoi(receivedNewVal);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            if(idOfNewVal > -1 && idOfNewVal < retTable->getSize())
            {
                retTable->setVal(idOfNewVal,newVal);
            }
            else
            {
                std::cout << undefinedObject;
            }
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

SetValueHandler::~SetValueHandler()
{}

