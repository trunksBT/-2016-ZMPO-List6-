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
class FlyweightMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = std::move(std::make_pair( MINUS_ONE, ERROR_CODE::INITIAL_VAL));
    }

    virtual void TearDown()
    {}
protected:
    Flyweight application;
    ResultCode rcVal;
};

TEST_F(FlyweightMT, getFinalResultCode_createDef_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDef0),
        application.interpretCommand(stub::createDef0),
        application.interpretCommand(stub::createDef0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightMT, getFinalResultCode_createDef_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDef0),
        application.interpretCommand(stub::createDefm1),
        application.interpretCommand(stub::createDef0)
    });

    ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
}

TEST_F(FlyweightMT, createDefm1_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDefm1);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(FlyweightMT, createDef0_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDef0);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(FlyweightMT, createDef6_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDef6);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(FlyweightMT, createDefs1_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDefs1);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(FlyweightMT, createDefs6_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDefs6);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(FlyweightMT, createDefs10_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDefs6);

    ASSERT_EQ(expVal, rcVal);
}

}

