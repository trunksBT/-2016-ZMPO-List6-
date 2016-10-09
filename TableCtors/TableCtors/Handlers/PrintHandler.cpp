#include "stdafx.h"
#include <iostream>

#include "PrintHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

PrintHandler::PrintHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void PrintHandler::perform(std::vector<CTable*>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::amount]);
    /*int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        if(wholeCommand_[idxOf::command] == messageLiterals::getSize)
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
    }*/
}

PrintHandler::~PrintHandler()
{}
