// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <boost/optional.hpp>
#include <boost/tokenizer.hpp>

#include "Interface.hpp"
#include "Utils.hpp"
#include "Stub.hpp"

int main()
{
    std::vector<std::string> tokenizedCommand(stub::createDef);
    std::string receivedCommand = tokenizedCommand[messageId::command];
    if (receivedCommand == messageLiterals::createDef)
    {
        std::cout << "Stworze tablice";
    }
    else
    {
        std::cout << "Nie znam takiej komendy";
    }

    std::cout << std::endl;
    return 0;
}
