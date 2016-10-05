#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "ConcreteFlyweights.h"

using namespace trigger;

std::vector<CTable*> Flyweight::cache;

CTable* Flyweight::callCtor(std::string& command, std::string& receivedId)
{
    int idx = std::stoi(receivedId);
    if(command == messageLiterals::createDef)
    {
        if(idx < cache.size())
        {
            delete cache[idx];
            cache[idx] = FlyweightCTable::onCreateDef();
        }
        else
        {
            std::cout << "Nie ma takiej tablicy" << defaultVals::POST_PRINT;
        }
    }
    else
    {
        std::cout << "Nie znam takiej komendy";
    }
    return cache[idx];
    return nullptr;
}


void Flyweight::insertStub(std::vector<CTable*> inVal)
{
    cache = inVal;
}

void Flyweight::releaseResources()
{
    for(auto i = 0; i < cache.size(); i++)
    {
        delete cache[i];
    }
    cache.clear();
}
