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

    return codeToString[inCode];
}

bool checkIfProperArguments(std::vector<std::string>& inCommand)
{
    //idxOf::amount;
    //constexpr int command = 0;
    //constexpr int idOfCTable = 1;
    //constexpr int amount = 1;
    //constexpr int newName = 2;
    //constexpr int goalId = 2;
    //constexpr int newVal = 3;
    return false;
}

}
