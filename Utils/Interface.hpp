#pragma once

#include <boost/tokenizer.hpp>
#include <ElementsAndTables/CTable.hpp>

namespace communication
{
std::vector<std::string> performLexer(std::string inCommand);
std::vector<std::string> receiveAndLexCommandFromUser();
};

