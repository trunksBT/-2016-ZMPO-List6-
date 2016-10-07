#include "stdafx.h"
#include "RAIIFlyweightCTable.h"
#include "Utils.hpp"
#include "Flyweight.h"

using namespace defaultVals;

RAIIFlyweightCTable::RAIIFlyweightCTable(std::vector<std::string>& inCommand)
{
   Flyweight::createFlyweight(INITIAL_FLYWEIGHT_CACHE_SIZE);
   Flyweight::receiveCommand(std::move(inCommand));
}

RAIIFlyweightCTable::RAIIFlyweightCTable(std::vector<std::string>& inCommand,
   std::vector<CTable*>& inCache)
{
   Flyweight::createFlyweight(inCache);
   Flyweight::receiveCommand(std::move(inCommand));
}

RAIIFlyweightCTable::~RAIIFlyweightCTable()
{
   Flyweight::releaseResources();
}

void RAIIFlyweightCTable::receiveCommand(std::vector<std::string>& inCommand)
{
    Flyweight::receiveCommand(std::move(inCommand));
}

