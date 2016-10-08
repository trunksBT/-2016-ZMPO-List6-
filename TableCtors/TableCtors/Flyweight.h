#pragma once

#include <string>
#include <vector>
#include "CTable.hpp"

class CreateDefHandler;
class CreateDefsHandler;
class RemoveHandler;
class RemoveAllHandler;
class SetNameHandler;
class GetHandler;

class Flyweight
{
    friend class CreateDefHandler;
    friend class CreateDefsHandler;
    friend class RemoveHandler;
    friend class RemoveAllHandler;
    friend class SetNameHandler;
    friend class GetHandler;
public:
    Flyweight();
    Flyweight(std::vector<std::string>& inCommand,
        std::vector<CTable*>& inCache);
    ~Flyweight();
public:
    static void createFlyweight(int inSize);
    static void createFlyweight(std::vector<CTable*>& inCache);
    static void interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
   static void releaseResources(std::vector<CTable*>& inCache);
private:
    static std::vector<CTable*> cache_;
};

