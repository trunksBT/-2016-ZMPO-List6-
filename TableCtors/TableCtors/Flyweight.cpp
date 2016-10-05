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
   int idxOrAmmount = std::stoi(receivedId);
   if(command == messageLiterals::createDef)
   {
      if(idxOrAmmount < cache.size())
      {
         if(cache[idxOrAmmount] != nullptr)
         {
            delete cache[idxOrAmmount];
         }
         cache[idxOrAmmount] = FlyweightCTable::onCreateDef();
      }
      else
      {
         std::cout << "Nie ma takiej tablicy" << defaultVals::POST_PRINT;
      }
   }
   else if(command == messageLiterals::createDefs)
   {
      if(idxOrAmmount < cache.size())
      {
         int cursorIdx = ZERO;
         for(int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmmount;)
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
