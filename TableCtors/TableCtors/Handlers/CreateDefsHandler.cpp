#include "stdafx.h"
#include <iostream>

#include "CreateDefsHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

CreateDefsHandler::CreateDefsHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void CreateDefsHandler::perform(std::vector<CTable*>& inCache)
{
    std::cout << wholeCommand_[idxOf::command] << POST_PRINT;

    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    if(idxOrAmount > inCache.size())
    {
        inCache.reserve(idxOrAmount);
    }
    int cacheSize = inCache.size();
    int cursorIdx = ZERO;
    for(int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount;)
    {
        if(cursorIdx < inCache.size())
        {
            if(inCache[cursorIdx] == nullptr)
            {
                inCache[cursorIdx] = CTable::buildNewObj();
                ammountOfCreatedObj++;
            }
        }
        else
        {
            inCache.emplace_back(CTable::buildNewObj());
            ammountOfCreatedObj++;

        }
        cursorIdx++;
    }
}

CreateDefsHandler::~CreateDefsHandler()
{}
