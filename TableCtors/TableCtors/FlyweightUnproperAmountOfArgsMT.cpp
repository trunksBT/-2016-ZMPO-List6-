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

TEST_F(FlyweightUnproperAmountOfArgsMT, createDefToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createDefToBig_OnEmptyFlyweight_Expect_ERROR_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createDefsToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefsToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createDefsToBig_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefsToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createCopy0ToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
//{
//    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createCopy0ToSmall)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}

//TEST_F(FlyweightUnproperAmountOfArgsMT, createCopy0ToBig_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
//{
//    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongAmountStub::createCopy0ToBig)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}

}

