#include "stdafx.h"
#include <iostream>
#include <boost/tokenizer.hpp>
#include "Utils.hpp"

using tokenizer = boost::tokenizer<boost::char_separator<char>>;

namespace communication
{

std::vector<std::string> performLexer(std::string inCommand)
{
    boost::char_separator<char> sep(defaultVals::SEPARATOR);
    tokenizer tokens(inCommand, sep);
    std::vector<std::string> retVal(tokens.begin(), tokens.end());
    return retVal;
}

std::vector<std::string> receiveAndLexCommandFromUser()
{
    std::cout << "$ ";

    std::string inChain;
    getline(std::cin, inChain);

    return performLexer(std::move(inChain));
}

};