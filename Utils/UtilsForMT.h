#pragma once

#include <utility>
#include <vector>

enum class ERROR_CODE;

using ResultCode = std::pair<int, ERROR_CODE>;

namespace assertWrapper
{
ResultCode getFinalResultCode(std::vector<ERROR_CODE> inCodes);
void printWrongCommandInfo(ResultCode rcVal);
void ASSERT_FOR_PAIR_WITH_PRINT( ERROR_CODE expVal, ResultCode rcVal);
void CHECK_IF_FINISHED_PROPER(ERROR_CODE expVal, ResultCode rcVal);
}

