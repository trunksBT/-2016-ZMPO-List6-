// Copyrights TrunkBT_KorytkoBT
#include "IHandler.h"
#include <iostream>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace funs;

IHandler::IHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    if(flags::PRINT_CTORS && flags::REPLY_COMMAND)
    {
        logger << PRE_PRINT << wholeCommand_[idxOf::COMMAND] << POST_PRINT;
    }
}

CODE IHandler::checkArgsAndPerform(InitializedCTable& inCache)
{
    if(!isProperNumberOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return returnResultCode(CODE::WRONG_AMOUNT_OF_ARGS);
    }
    else if(!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return returnResultCode(CODE::ERROR_ARGS_PARSING);
    }
    else
    {
        return performOn(inCache);
    }
}

IHandler::~IHandler()
{
    if(flags::PRINT_CTORS)
    {
        logger << POST_PRINT;
    }
}
