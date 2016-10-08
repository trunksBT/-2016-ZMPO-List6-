#include "stdafx.h"
#include "IHandler.h"


IHandler::IHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = std::move(inCommand);
}

IHandler::~IHandler()
{}
