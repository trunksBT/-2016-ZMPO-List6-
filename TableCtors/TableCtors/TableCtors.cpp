// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <boost/optional.hpp>
#include <boost/tokenizer.hpp>

#include "Stub.hpp"
#include "Utils.hpp"
#include "CTable.hpp"
#include "Interface.hpp"
#include "TableCtors.h"

using namespace defaultVals;
using namespace communication;

int main()
{
    {
        std::vector<CTable*> tables(stub::threeTables);
        std::vector<std::string> tokenizedCommand(stub::createDef);
        std::string receivedCommand = tokenizedCommand[idxOf::command];
        std::string receivedId = tokenizedCommand[idxOf::id];

        communication::perform(receivedCommand, receivedId, tables);

        CTable::releaseResources(tables);
    }

    std::cout << std::endl;
    return 0;
}


