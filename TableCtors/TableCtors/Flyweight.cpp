#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"

using namespace defaultVals;

std::vector<CTable*> Flyweight::cache_;
std::vector<std::string> Flyweight::command_;

void Flyweight::createFlyweight(int inSize)
{
   cache_ = std::vector<CTable*>(inSize);
}

Flyweight::Flyweight(std::vector<std::string>& inCommand)
{
    Flyweight::createFlyweight(INITIAL_FLYWEIGHT_CACHE_SIZE);
    Flyweight::receiveCommand(std::move(inCommand));
}

Flyweight::Flyweight(std::vector<std::string>& inCommand,
    std::vector<CTable*>& inCache)
{
    Flyweight::createFlyweight(inCache);
    Flyweight::receiveCommand(std::move(inCommand));
}

Flyweight::~Flyweight()
{
    Flyweight::releaseResources();
}

void Flyweight::createFlyweight(std::vector<CTable*>& inCache)
{
   cache_ = std::move(inCache);
}

void Flyweight::interpretCommand(std::string& command, std::string& receivedId)
{
   int idxOrAmount = std::stoi(receivedId);
   if(command == messageLiterals::createDef)
   {
      if(idxOrAmount < cache_.size())
      {
         if(cache_[idxOrAmount] != nullptr)
         {
            delete cache_[idxOrAmount];
         }
         cache_[idxOrAmount] = new CTable();
      }
      else
      {
         std::cout << "Nie ma takiej tablicy" << POST_PRINT;
      }
   }
   else if(command == messageLiterals::createDefs)
   {
      if(idxOrAmount > cache_.size())
      {
         cache_.reserve(idxOrAmount);
      }
      int cacheSize = cache_.size();
      int cursorIdx = ZERO;
      for(int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount;)
      {
         if(cursorIdx < cache_.size())
         {
            if(cache_[cursorIdx] == nullptr)
            {
               cache_[cursorIdx] = new CTable();
               ammountOfCreatedObj++;
            }
            cursorIdx++;
         }
         else
         {
            cache_.emplace_back( new CTable() );
            ammountOfCreatedObj++;
            cursorIdx++;
         }
      }
   }
   else if(command.find(messageLiterals::get) != std::string::npos)
   {
       if(idxOrAmount > cache_.size() || idxOrAmount > cache_.size() < 0)
       {
           std::cout << "Index poza zasiegiem pamieci" << POST_PRINT;
       }
       else
       {
           std::cout << INDENT;
           if(command == messageLiterals::getName)
           {
               std::cout << messageLiterals::getName << SEPARATOR;
               {
                   CTable* retTable = cache_.at(idxOrAmount);
                   if(retTable != nullptr)
                   {
                       std::cout << retTable->getName();
                   }
                   else
                   {
                       std::cout << "Null ptr";
                   }
                   retTable == nullptr;
               }

           }
           else if(command == messageLiterals::getSize)
           {
               std::cout << messageLiterals::getSize << SEPARATOR;
               {
                   CTable* retTable = cache_.at(idxOrAmount);
                   if(retTable != nullptr)
                   {
                       std::cout << retTable->getSize();
                   }
                   retTable == nullptr;
               }

           }
           else
           {
               std::cout << "Nie znam takiej komendy" << POST_PRINT;
           }
           std::cout << POST_PRINT;
       }
   }
   else if(command == messageLiterals::remove)
   {
       if(idxOrAmount > cache_.size() || idxOrAmount > cache_.size() < 0)
       {
           std::cout << "Index poza zasiegiem pamieci" << POST_PRINT;
       }
       else
       {
           std::cout << INDENT << messageLiterals::remove << SEPARATOR;
           {
               CTable* retTable = cache_.at(idxOrAmount);
               if(retTable != nullptr)
               {
                   std::cout << retTable->getName() << POST_PRINT;
               }
               delete retTable;
               cache_.at(idxOrAmount) = nullptr;
           }
       }
   }
   else if(command == messageLiterals::removeAll)
   {
       std::cout << INDENT << messageLiterals::removeAll << POST_PRINT;
       releaseResources();
       std::cout << POST_PRINT;
   }
   else
   {
      std::cout << "Nie znam takiej komendy" << POST_PRINT;
   }
}

void Flyweight::receiveCommand(std::vector<std::string>& inCommand)
{
   command_ = std::move(inCommand);
   std::string commandName = command_[idxOf::command];

   std::string idOrAmmountVal;
   if(command_.size() < 2)
   {
       idOrAmmountVal = string999;
   }
   else
   {
       idOrAmmountVal = command_[idxOf::idOrAmmount];
   }

   interpretCommand(commandName, idOrAmmountVal);
}

void Flyweight::releaseResources()
{
   releaseResources(cache_);
}

void Flyweight::receiveCommandFromUpper(std::vector<std::string>& inCommand)
{
    Flyweight::receiveCommand(std::move(inCommand));
}

void Flyweight::releaseResources(std::vector<CTable*>& inCache)
{
   for(auto i = ZERO; i < inCache.size(); i++)
   {
      delete inCache[i];
   }
   inCache.clear();
}
