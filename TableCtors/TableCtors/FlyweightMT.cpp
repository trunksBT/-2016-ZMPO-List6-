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

TEST_F(FlyweightMT, createDef0_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDef0);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(FlyweightMT, createDefm1_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUND;
    ERROR_CODE rcVal;

    rcVal = application.interpretCommand(stub::createDefm1);

    ASSERT_EQ(expVal, rcVal);
}
}

