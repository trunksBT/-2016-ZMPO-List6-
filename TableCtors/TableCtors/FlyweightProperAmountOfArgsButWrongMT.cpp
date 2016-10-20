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
class CCFlyweightProperAmountOfArgsButWrongMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = std::move(std::make_pair(MINUS_ONE, ERROR_CODE::INITIAL_VAL));
    }

    virtual void TearDown()
    {}
protected:
    CFlyweight application;
    ResultCode rcVal;
};

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createDefZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createDefZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createDefsZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createDefsZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createCopyZZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createCopyZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, printZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::printZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, getNameZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getNameZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, getSizeZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getSizeZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, deleteZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::deleteZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, setNameZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::setNameZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, getValueZZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getValueZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, setValue0ZZZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::setValue0ZZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, setSizeZZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::setSizeZZ)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createZZZ_OnEmptyCCFlyweight_Expect_ERROR_ARGS_PARSING)
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
