#pragma once

#include <string>
#include <vector>
#include "CTable.hpp"

class Flyweight
{
public:
    static void createFlyweight(int inSize);
    static void callCtor(std::string& command, std::string& receivedId);
    static void createCTable(std::vector<std::string>& command);
public:
    static void releaseResources();
private:
    static std::vector<CTable*> cache;
    static std::vector<std::string> command;
};

