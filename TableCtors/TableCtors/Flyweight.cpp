#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "Handlers/CreateHandler.h"
#include "Handlers/CreateDefHandler.h"
#include "Handlers/CreateDefsHandler.h"
#include "Handlers/RemoveHandler.h"
#include "Handlers/RemoveAllHandler.h"
#include "Handlers/SetNameHandler.h"
#include "Handlers/SetValueHandler.h"
#include "Handlers/GetNameHandler.h"
#include "Handlers/GetSizeHandler.h"
#include "Handlers/GetValueHandler.h"
#include "Handlers/CreateCopyHandler.h"
#include "Handlers/PrintHandler.h"
#include "Handlers/PrintAllHandler.h"
#include "Handlers/ChangeSizeHandler.h"
#include "Handlers/HelpHandler.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

std::vector<CTable*> CFlyweight::cache_;

ERROR_CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    if(inCommand.size() == ZERO)
    {
        return ERROR_CODE::ERROR_COMMAND_PARSING;
    }

    ERROR_CODE returnedCode = ERROR_CODE::INITIAL_VAL;
    std::string command(inCommand[idxOf::command]);

    if(command == messageLiterals::create)
    {
        CCreateHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::createDef)
    {
        CCreateDefHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::createDefs)
    {
        CCreateDefsHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::createCopy)
    {
        CCreateCopyHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::remove)
    {
        CRemoveHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::removeAll)
    {
        CRemoveAllHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::setName)
    {
        CSetNameHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::setValue)
    {
        CSetValueHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::getName)
    {
        CGetNameHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::getSize)
    {
        CGetSizeHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::getValue)
    {
        CGetValueHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::print)
    {
        CPrintHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::printAll)
    {
        CPrintAllHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::changeSize)
    {
        CChangeSizeHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::help)
    {
        CHelpHandler evaluate(inCommand);
        returnedCode = evaluate.performOn(cache_);
    }
    else if(command == messageLiterals::close)
    {
        returnedCode = ERROR_CODE::CLOSE;
    }
    else
    {
        returnedCode = ERROR_CODE::ERROR_COMMAND_PARSING;
        if(flag::printOn)
        {
            std::cout << toString(returnedCode);
        }
    }

    return returnedCode;
}

#pragma region ********** CTORS_DTORS **********

void CFlyweight::createCFlyweight(int inSize)
{
    cache_ = std::vector<CTable*>(inSize);
}

void CFlyweight::releaseResources()
{
    releaseResources(cache_);
}

void CFlyweight::releaseResources(std::vector<CTable*>& inCache)
{
    for(auto i = ZERO; i < inCache.size(); i++)
    {
        delete inCache[i];
    }
    inCache.clear();
}

CFlyweight::CFlyweight()
{
    CFlyweight::createCFlyweight(INITIAL_FLYWEIGHT_CACHE_SIZE);
}

CFlyweight::CFlyweight(std::vector<std::string>& inCommand,
    std::vector<CTable*>& inCache)
{
    CFlyweight::createCFlyweight(inCache);
    CFlyweight::interpretCommand(std::move(inCommand));
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}

void CFlyweight::createCFlyweight(std::vector<CTable*>& inCache)
{
    cache_ = std::move(inCache);
}

# pragma endregion
