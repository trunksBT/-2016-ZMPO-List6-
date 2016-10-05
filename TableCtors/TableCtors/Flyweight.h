#pragma once

#include <string>
#include <vector>
#include "CTable.hpp"

class Flyweight
{
public:
    static CTable* callCtor(std::string& command, std::string& receivedId);
public:
    static void insertStub(std::vector<CTable*> inVal);
    static void releaseResources();
private:
    static std::vector<CTable*> cache;
    static std::vector<std::string> commands;
};

