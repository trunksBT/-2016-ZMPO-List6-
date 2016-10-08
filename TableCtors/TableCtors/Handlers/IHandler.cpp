#include "stdafx.h"
#include "IHandler.h"
#include <iostream>
#include "../Utils.hpp"

using namespace defaultVals;

IHandler::IHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    std::cout << PRE_PRINT;
}

IHandler::~IHandler()
{
    std::cout << POST_PRINT;
}
