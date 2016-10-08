#include "stdafx.h"
#include <iostream>

#include "GetHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

GetHandler::GetHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void GetHandler::perform(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount > inCache.size() || idxOrAmount > inCache.size() < 0)
    {
        std::cout << indexOutOfBound << POST_PRINT;
    }
    else
    {
        std::cout << INDENT;
        if(wholeCommand_[idxOf::command] == messageLiterals::getName)
        {
            std::cout << messageLiterals::getName << SEPARATOR;
            {
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
        }
        else if(wholeCommand_[idxOf::command] == messageLiterals::getSize)
        {
            std::cout << messageLiterals::getSize << SEPARATOR;
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

        }
        else
        {
            std::cout << undefinedCommand << POST_PRINT;
        }
        std::cout << POST_PRINT;
    }
}

GetHandler::~GetHandler()
{}
