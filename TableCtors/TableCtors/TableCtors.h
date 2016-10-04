#pragma once

void releaseResources(std::vector<CTable *> &tables);

void perform(std::string &receivedCommand, std::string &receivedId, std::vector<CTable *> &tables);
