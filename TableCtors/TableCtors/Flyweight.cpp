#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"

using namespace defaultVals;
using namespace logLiterals;

std::vector<CTable*> Flyweight::cache_;
std::vector<std::string> Flyweight::command_;

void Flyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    std::string command(command_[idxOf::command]);
    if(command == messageLiterals::createDef)
    {
        std::string receivedId(command_[idxOf::id]);
        int idxOrAmount = std::stoi(receivedId);
        if(idxOrAmount < cache_.size())
        {
            if(cache_[idxOrAmount] != nullptr)
            {
                delete cache_[idxOrAmount];
            }
            cache_[idxOrAmount] = CTable::buildNewObj();
        }
        else
        {
            std::cout << undefinedObject << POST_PRINT;
        }
    }
    else if(command == messageLiterals::createDefs)
    {
        std::string receivedId(command_[idxOf::amount]);
        int idxOrAmount = std::stoi(receivedId);
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
                    cache_[cursorIdx] = CTable::buildNewObj();
                    ammountOfCreatedObj++;
                }
                cursorIdx++;
            }
            else
            {
                cache_.emplace_back(CTable::buildNewObj());
                ammountOfCreatedObj++;
                cursorIdx++;
            }
        }
    }
    else if(command.find(messageLiterals::get) != std::string::npos)
    {
        std::string receivedId(command_[idxOf::amount]);
        int idxOrAmount = std::stoi(receivedId);
        if(idxOrAmount > cache_.size() || idxOrAmount > cache_.size() < 0)
        {
            std::cout << indexOutOfBound << POST_PRINT;
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
                        std::cout << undefinedObject;
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
                std::cout << undefinedCommand << POST_PRINT;
            }
            std::cout << POST_PRINT;
        }
    }
    else if(command == messageLiterals::remove)
    {
        std::string receivedId(command_[idxOf::amount]);
        int idxOrAmount = std::stoi(receivedId);
        if(idxOrAmount > cache_.size() || idxOrAmount > cache_.size() < 0)
        {
            std::cout << indexOutOfBound << POST_PRINT;
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
    }
    else if(command == messageLiterals::setName)
    {
        std::string newName(command_[idxOf::newName]);
        std::string receivedId(std::move(command_[idxOf::amount]));
        int idxOrAmount = std::stoi(receivedId);
        if(idxOrAmount > cache_.size() || idxOrAmount > cache_.size() < 0)
        {
            std::cout << indexOutOfBound << POST_PRINT;
        }
        else
        {
            std::cout << INDENT << messageLiterals::setName << POST_PRINT;
            {
                cache_[idxOrAmount]->setName(newName);
            }
        }
    }
    else
    {
        std::cout << undefinedCommand << POST_PRINT;
    }
}

void Flyweight::receiveCommand(std::vector<std::string>& inCommand)
{
    command_ = std::move(inCommand);
    interpretCommand(inCommand);
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

# pragma endregion
