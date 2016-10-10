#include "stdafx.h"
#include "Utils.hpp"
#include <map>
#include <string>

using namespace defaultVals;

namespace funs
{

bool isProperIdx(int idxOrAmount, std::vector<CTable*>& inCache)
{
    return idxOrAmount > MINUS_ONE && idxOrAmount < inCache.size();
}

bool isProperIdx(int idx, int size)
{
    return idx > MINUS_ONE && idx < size;
}

std::string toString(ERROR_CODE inCode)
{
    static std::map<ERROR_CODE, std::string> codeToString;

    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::SEEMS_LEGIT),
        std::forward_as_tuple("SEEMS_LEGIT"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::UNDEFINED_OBJECT),
        std::forward_as_tuple("UNDEFINED_OBJECT"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::INDEX_OUT_OF_BOUNDS),
        std::forward_as_tuple("INDEX_OUT_OF_BOUND"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::ERROR_COMMAND_PARSING),
        std::forward_as_tuple("ERROR_COMMAND_PARSING"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::NOT_HANDLED_ERROR_REPORTING),
        std::forward_as_tuple("NOT_HANDLED_ERROR_REPORTING"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::INITIAL_VAL),
        std::forward_as_tuple("INITIAL_VAL"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::WRONG_AMOUNT_OF_ARGS),
        std::forward_as_tuple("WRONG_AMOUNT_OF_ARGS"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::ERROR_ARGS_PARSING),
        std::forward_as_tuple("ERROR_ARGS_PARSING"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::WRONG_VALUE),
        std::forward_as_tuple("WRONG_VALUE"));
    codeToString.emplace(std::piecewise_construct,
        std::forward_as_tuple(ERROR_CODE::CLOSE),
        std::forward_as_tuple("CLOSE"));

    return codeToString[inCode];
}

bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs)
{
    return inCommand.size() >= inProperAmountOfArgs;
}

bool isNumber(std::string inChain)
{
    bool isNumber = true;

    for(int i = 0; i< inChain.size() && isNumber; i++)
    {
        if(i == 0 && inChain[i] == '-')
        {
            isNumber &= true;
        }
        else if(isdigit(inChain[i]))
        {
            isNumber &= true;
        }
        else
        {
            isNumber &= false;
        }
    }

    return isNumber;
}

bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs)
{
    bool isProperType = true;
    for(int i = 0; i < inCommand.size() && isProperType; i++)
    {
        if(inProperTypeOfArgs[i] == intType && !isNumber(inCommand[i]))
        {
            isProperType &= false;
        }
    }
    return isProperType;
}

}
