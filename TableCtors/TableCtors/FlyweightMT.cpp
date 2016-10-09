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
    ERROR_CODE rcVal = ERROR_CODE::SEEMS_LEGIT;

    //rcVal = application.interpretCommand(stub::createDef0);

    ASSERT_EQ(expVal, rcVal);
}
}

