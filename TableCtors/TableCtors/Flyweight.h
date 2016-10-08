#pragma once

#include <string>
#include <vector>
#include "CTable.hpp"

class Flyweight
{
public:
    Flyweight(std::vector<std::string>& inCommand);
    Flyweight(std::vector<std::string>& inCommand,
        std::vector<CTable*>& inCache);
    ~Flyweight();
public:
    static void createFlyweight(int inSize);
    static void createFlyweight(std::vector<CTable*>& inCache);
    static void interpretCommand(std::vector<std::string>& inCommand);    static void receiveCommand(std::vector<std::string>& command);
public:
   static void releaseResources();
   static void releaseResources(std::vector<CTable*>& inCache);
private:
    static std::vector<CTable*> cache_;
    static std::vector<std::string> command_;
};

