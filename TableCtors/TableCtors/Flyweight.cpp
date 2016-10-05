#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "ConcreteFlyweights.h"

using namespace trigger;

std::vector<CTable*> Flyweight::cache;
std::vector<std::string> Flyweight::command;

void Flyweight::createFlyweight(int inSize)
{
    cache = std::vector<CTable*>(inSize);
}

void Flyweight::callCtor(std::string& command, std::string& receivedId)
{
    int idx = std::stoi(receivedId);
    if(command == messageLiterals::createDef)
    {
        if(idx < cache.size())
        {
            if(cache[idx] != nullptr)
            {
                delete cache[idx];
            }
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
}

void Flyweight::createCTable(std::vector<std::string>& inCommand)
{
    command = std::move(inCommand);
    callCtor(command[idxOf::command], command[idxOf::id]);
}

void Flyweight::releaseResources()
{
    for(auto i = 0; i < cache.size(); i++)
    {
        delete cache[i];
    }
    cache.clear();
}
