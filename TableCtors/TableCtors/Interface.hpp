#pragma once
#include <boost/tokenizer.hpp>

#include "CTable.hpp"
namespace communication
{
std::vector<std::string> receiveCommandFromUser();
void perform(std::string &receivedCommand, std::string &receivedId,
    std::vector<CTable *> &tables);

namespace trigger
{
CTable* onCreateDef();
}
};

