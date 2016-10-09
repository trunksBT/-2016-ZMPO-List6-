#pragma once

#include <string>
#include <vector>
#include "CTable.hpp"
#include "Utils.hpp"

class CreateDefHandler;
class CreateDefsHandler;
class CreateCopyHandler;
class RemoveHandler;
class RemoveAllHandler;
class SetNameHandler;
class GetHandler;
class CreateCopyHandler;
class GetNameHandler;
class GetSizeHandler;
class GetValueHandler;
class SetValueHandler;
class PrintHandler;

class Flyweight
{
    friend class CreateDefHandler;
    friend class CreateDefsHandler;
    friend class CreateCopyHandler;
    friend class RemoveHandler;
    friend class RemoveAllHandler;
    friend class SetNameHandler;
    friend class SetValueHandler;
    friend class GetHandler;
    friend class GetNameHandler;
    friend class GetSizeHandler;
    friend class GetValueHandler;
    friend class PrintHandler;
public:
    Flyweight();
    Flyweight(std::vector<std::string>& inCommand,
        std::vector<CTable*>& inCache);
    ~Flyweight();
public:
    static void createFlyweight(int inSize);
    static void createFlyweight(std::vector<CTable*>& inCache);
    static ERROR_CODE interpretCommand(std::vector<std::string>& inCommand);
    static ERROR_CODE interpretProperCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
   static void releaseResources(std::vector<CTable*>& inCache);
private:
    static std::vector<CTable*> cache_;
};

