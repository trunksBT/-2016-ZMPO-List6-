#include "stdafx.h"
#include "UtilsForMT.h"

#include <gtest/gtest.h>
#include "Utils.hpp"

using namespace defaultVals;
using namespace funs;

namespace assertWrapper
{
ResultCode getFinalResultCode(std::vector<ERROR_CODE> inCodes)
{
    bool isLegit = true;
    ERROR_CODE resultCode = ERROR_CODE::INITIAL_VAL;
    int idxOfWrongCode = MINUS_ONE;

    for(int i = 0; i < inCodes.size() && isLegit; i++)
    {
        if(inCodes[i] == ERROR_CODE::SEEMS_LEGIT)
        {
            isLegit &= true;
            resultCode = ERROR_CODE::SEEMS_LEGIT;
        }
        else
        {
            isLegit &= false;
            resultCode = inCodes[i];
            idxOfWrongCode = i;
        }
    }

    return std::move(std::make_pair(idxOfWrongCode, resultCode));
}

void printWrongCommandInfo(ResultCode rcVal)
{
    if(std::get<ZERO>(rcVal) != MINUS_ONE && flag::PRINT_ON)
    {
        std::cout
            << std::endl
            << ERRORED_COMMAND_IDX
            << SEPARATOR
            << std::get<ZERO>(rcVal)
            << COMMA_SPACE
            << toString(std::get<ONE>(rcVal))
            << POST_PRINT;
    }
}

void ASSERT_FOR_PAIR_WITH_PRINT( ERROR_CODE expVal, ResultCode rcVal)
{
    if(expVal == std::get<ONE>(rcVal))
    {
        ASSERT_TRUE(true);
    }
    else
    {
        printWrongCommandInfo(std::move(rcVal));
        ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    }
}

void CHECK_IF_FINISHED_PROPER(ERROR_CODE expVal, ResultCode rcVal)
{
    if(expVal == std::get<ONE>(rcVal))
    {
        std::cout << toString(std::get<ONE>(rcVal)) << POST_PRINT;
    }
    else
    {
        printWrongCommandInfo(std::move(rcVal));
    }
}
}