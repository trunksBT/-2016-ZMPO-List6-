#include "stdafx.h"
#include <gtest/gtest.h>

#include <limits>
#include <vector>
#include "Flyweight.h"
#include <string>
#include "Stub.hpp"

namespace
{
class FlyweightMT : public testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
protected:
    Flyweight application;
};

ERROR_CODE getFinalResultCode(std::vector<ERROR_CODE> inCodes)
{
    bool isLegit = true;
    ERROR_CODE resultCode;

    for(auto it = inCodes.begin(); it != inCodes.end() && isLegit; it++)
    {
        if(*it == ERROR_CODE::SEEMS_LEGIT)
        {
            isLegit &= true;
        }
        else
        {
            isLegit &= false;
        }
    }

    if(isLegit)
    {
        resultCode = ERROR_CODE::SEEMS_LEGIT;
    }
    else
    {
        resultCode = ERROR_CODE::ERROR_IN_SEQUENCE;
    }

    return resultCode;
}

TEST_F(FlyweightMT, createDefm1_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUND;
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
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUND;
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

TEST_F(FlyweightMT, createDefs10_y_getName0_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
    ERROR_CODE rcVal1 = ERROR_CODE::NOT_INITIALIZED;
    ERROR_CODE rcVal2 = ERROR_CODE::NOT_INITIALIZED;
    ERROR_CODE totalRcVal;

    rcVal1 = application.interpretCommand(stub::createDefs6);
    //rcVal2 = application.interpretCommand(stub::getName0);

    totalRcVal = getFinalResultCode({ rcVal1, rcVal2 });
    ASSERT_EQ(expVal, totalRcVal);
}

}

