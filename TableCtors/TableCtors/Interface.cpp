#include "stdafx.h"
#include <iostream>

#include <boost/tokenizer.hpp>

#include "Utils.hpp"
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

};