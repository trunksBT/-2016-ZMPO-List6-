#include "stdafx.h"
#include <iostream>

#include <boost/tokenizer.hpp>

#include "Utils.h"
#include "Interface.h"

using tokenizer = boost::tokenizer<boost::char_separator<char>>;

namespace communication
{
std::vector<std::string> receiveCommandFromUser()
{
    std::cout << "Pass command" << std::endl;
    std::cout << "$ ";
    
    std::string inChain;
    getline(std::cin, inChain);
    
    boost::char_separator<char> sep(SEPARATOR);
    tokenizer tokens(inChain, sep);
    std::vector<std::string> retVal(tokens.begin(), tokens.end());
    
    return std::move(retVal);
}

};