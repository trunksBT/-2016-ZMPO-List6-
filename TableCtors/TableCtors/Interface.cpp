#include "stdafx.h"
#include <iostream>

#include <boost/tokenizer.hpp>

#include "Utils.hpp"
#include "CTable.hpp"
#include "Interface.hpp"

using tokenizer = boost::tokenizer<boost::char_separator<char>>;

namespace communication
{
std::vector<std::string> receiveCommandFromUser()
{
    std::cout << "Pass command" << std::endl;
    std::cout << "$ ";
    
    std::string inChain;
    getline(std::cin, inChain);
    
    boost::char_separator<char> sep(defaultVals::SEPARATOR);
    tokenizer tokens(inChain, sep);
    std::vector<std::string> retVal(tokens.begin(), tokens.end());
    
    return std::move(retVal);
}

void perform(std::string &receivedCommand, std::string &receivedId,
    std::vector<CTable *> &tables)
{
    if (receivedCommand == messageLiterals::createDef)
    {
        if (int idx = std::stoi(receivedId) < tables.size())
        {
            delete tables[idx];
            tables[idx] = trigger::onCreateDef();
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

namespace trigger
{
CTable* onCreateDef()
{
    return new CTable();
}
}

};