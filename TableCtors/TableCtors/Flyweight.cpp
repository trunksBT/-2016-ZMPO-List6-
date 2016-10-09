#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "Handlers/CreateDefHandler.h"
#include "Handlers/CreateDefsHandler.h"
#include "Handlers/RemoveHandler.h"
#include "Handlers/RemoveAllHandler.h"
#include "Handlers/SetNameHandler.h"
#include "Handlers/SetValueHandler.h"
#include "Handlers/GetHandler.h"
#include "Handlers/GetNameHandler.h"
#include "Handlers/GetSizeHandler.h"
#include "Handlers/GetValueHandler.h"
#include "Handlers/CreateCopyHandler.h"

using namespace defaultVals;
using namespace logLiterals;

std::vector<CTable*> Flyweight::cache_;

void Flyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    std::string command(inCommand[idxOf::command]);
    if(command == messageLiterals::createDef)
    {
        CreateDefHandler handle(inCommand);
    }
    else if(command == messageLiterals::createDefs)
    {
        CreateDefsHandler handle(inCommand);
    }
    else if(command == messageLiterals::createCopy)
    {
        CreateCopyHandler handle(inCommand);
    }
    else if(command == messageLiterals::remove)
    {
        RemoveHandler handle(inCommand);
    }
    else if(command == messageLiterals::removeAll)
    {
        RemoveAllHandler handle(inCommand);
    }
    else if(command == messageLiterals::setName)
    {
        SetNameHandler handle(inCommand);
    }
    else if(command == messageLiterals::setValue)
    {
        SetValueHandler handle(inCommand);
    }
    else if(command == messageLiterals::getName)
    {
        GetNameHandler handle(inCommand);
    }
    else if(command == messageLiterals::getSize)
    {
        GetSizeHandler handle(inCommand);
    }
    else if(command == messageLiterals::getValue)
    {
        GetValueHandler handle(inCommand);
    }
    else
    {
        std::cout << undefinedCommand << POST_PRINT;
    }
}

#pragma region ********** CTORS_DTORS **********

void Flyweight::createFlyweight(int inSize)
{
    cache_ = std::vector<CTable*>(inSize);
}

void Flyweight::releaseResources()
{
    releaseResources(cache_);
}

void Flyweight::releaseResources(std::vector<CTable*>& inCache)
{
    for(auto i = ZERO; i < inCache.size(); i++)
    {
        delete inCache[i];
    }
    inCache.clear();
}

Flyweight::Flyweight()
{
    Flyweight::createFlyweight(INITIAL_FLYWEIGHT_CACHE_SIZE);
}

Flyweight::Flyweight(std::vector<std::string>& inCommand,
    std::vector<CTable*>& inCache)
{
    Flyweight::createFlyweight(inCache);
    Flyweight::interpretCommand(std::move(inCommand));
}

Flyweight::~Flyweight()
{
    Flyweight::releaseResources();
}

void Flyweight::createFlyweight(std::vector<CTable*>& inCache)
{
    cache_ = std::move(inCache);
}

# pragma endregion
