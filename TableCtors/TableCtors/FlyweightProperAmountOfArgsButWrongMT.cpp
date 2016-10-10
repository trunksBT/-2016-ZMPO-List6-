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

TEST_F(FlyweightProperAmountOfArgsButWrongMT, createDefsZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createDefsZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, createCopyZZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createCopyZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, printZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::printZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, getNameZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getNameZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, getSizeZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getSizeZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, removeZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::removeZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, setNameZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::setNameZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, getValueZZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getValueZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, setValue0ZZZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::setValue0ZZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperAmountOfArgsButWrongMT, changeSizeZZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::changeSizeZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(FlyweightProperAmountOfArgsButWrongMT, createZZZ_OnEmptyFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createZZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

}
