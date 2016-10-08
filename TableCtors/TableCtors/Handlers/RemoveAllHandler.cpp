#include "stdafx.h"
#include <iostream>

#include "RemoveAllHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;

RemoveAllHandler::RemoveAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    perform(Flyweight::cache_);
}

void RemoveAllHandler::perform(std::vector<CTable*>& inCache)
{
    std::cout << messageLiterals::removeAll << POST_PRINT;
}

RemoveAllHandler::~RemoveAllHandler()
{
    Flyweight::releaseResources();
}
