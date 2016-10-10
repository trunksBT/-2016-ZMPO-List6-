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
class FlyweightUnproperAmountOfArgsMT : public testing::Test
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

TEST_F(FlyweightUnproperAmountOfArgsMT, createDef_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    ASSERT_TRUE(false);
    //rcVal = getFinalResultCode
    //({
    //    application.interpretCommand(wrongAmountStub::createDef)
    //});

    //ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    //printWrongCommandInfo(std::move(rcVal));
}

}

