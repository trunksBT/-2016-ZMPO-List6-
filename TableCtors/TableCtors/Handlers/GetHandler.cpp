#include "stdafx.h"
#include <iostream>

#include "GetHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

GetHandler::GetHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void GetHandler::perform(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        if(wholeCommand_[idxOf::command] == messageLiterals::getName)
        {
            std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

            CTable* retTable = inCache.at(idxOrAmount);
            if(retTable != nullptr)
            {
                std::cout << retTable->getName();
            }
            else
            {
                std::cout << undefinedObject;
            }
            retTable == nullptr;
        }
        else if(wholeCommand_[idxOf::command] == messageLiterals::getSize)
        {
            std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

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
            std::cout << undefinedCommand;
        }
    }
    else
    {
        std::cout << indexOutOfBound;
    }
}

GetHandler::~GetHandler()
{
}

