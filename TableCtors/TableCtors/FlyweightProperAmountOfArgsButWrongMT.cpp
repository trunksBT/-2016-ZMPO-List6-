#include "stdafx.h"
#include <gtest/gtest.h>

#include <limits>
#include <vector>
#include <string>
#include <utility>

#include "Flyweight.h"
#include "Stub.hpp"
#include "UtilsForMT.h"

using namespace defaultVals;
using namespace assertWrapper;

namespace
{
class FlyweightProperAmountOfArgsButWrongMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = std::move(std::make_pair(MINUS_ONE, ERROR_CODE::INITIAL_VAL));
    }

    virtual void TearDown()
    {}
protected:
    Flyweight application;
    ResultCode rcVal;
};

TEST_F(FlyweightProperAmountOfArgsButWrongMT, createDefZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createDefZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

}
