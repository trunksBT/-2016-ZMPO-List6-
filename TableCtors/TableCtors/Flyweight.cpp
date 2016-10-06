#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "ConcreteFlyweights.h"

using namespace trigger;
using namespace defaultVals;

std::vector<CTable*> Flyweight::cache;
std::vector<std::string> Flyweight::command;

void Flyweight::createFlyweight(int inSize)
{
   cache = std::vector<CTable*>(inSize);
}

void Flyweight::createFlyweight(std::vector<CTable*>& inCache)
{
   cache = std::move(inCache);
}

void Flyweight::callCtor(std::string& command, std::string& receivedId)
{
   int idxOrAmount = std::stoi(receivedId);
   if(command == messageLiterals::createDef)
   {
      if(idxOrAmount < cache.size())
      {
         if(cache[idxOrAmount] != nullptr)
         {
            delete cache[idxOrAmount];
         }
         cache[idxOrAmount] = FlyweightCTable::onCreateDef();
      }
      else
      {
         std::cout << "Nie ma takiej tablicy" << defaultVals::POST_PRINT;
      }
   }
   else if(command == messageLiterals::createDefs)
   {
      if(idxOrAmount > cache.size())
      {
         cache.reserve(idxOrAmount);
      }
      int cacheSize = cache.size();
      int cursorIdx = ZERO;
      for(int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount;)
      {
         if(cursorIdx < cache.size())
         {
            if(cache[cursorIdx] == nullptr)
            {
               cache[cursorIdx] = FlyweightCTable::onCreateDef();
               ammountOfCreatedObj++;
            }
            cursorIdx++;
         }
         else
         {
            cache.emplace_back(FlyweightCTable::onCreateDef());
            ammountOfCreatedObj++;
            cursorIdx++;
         }
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
   callCtor(command[idxOf::command], command[idxOf::idOrAmmount]);
}

void Flyweight::releaseResources()
{
   releaseResources(cache);
}

void Flyweight::releaseResources(std::vector<CTable*>& inCache)
{
   for(auto i = ZERO; i < inCache.size(); i++)
   {
      delete inCache[i];
   }
   inCache.clear();
}
