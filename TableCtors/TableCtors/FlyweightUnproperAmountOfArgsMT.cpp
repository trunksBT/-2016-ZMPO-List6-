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

TEST_F(FlyweightUnproperAmountOfArgsMT, createDefsToBig_OnEmptyFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefsToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createCopy0ToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createCopy0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createCopy0ToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createCopy0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, printToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::printToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, printToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::printToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getNameToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getNameToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getNameToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getNameToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getSizeToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getSizeToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getSizeToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getSizeToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, removeToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::removeToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, removeToBig_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::removeToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, removeAllToBig_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::removeAllToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, setName0ToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setName0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, setName0ToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setName0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getValue0ToToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getValue0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getValue0ToToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getValue0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, getValueToBig_1_23_3_4_5_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getValueToBig_1_23_3_4_5)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, setValue0_0ToSmall_OnEmptyFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setValue0_0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, setValue0_0ToBig_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setValue0_0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, wrongCommandToSmall_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::wrongCommandToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, wrongCommandToBig_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::wrongCommandToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, changeSizeToSmall_getValue0_1_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::changeSizeToSmall),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, changeSizeToBig_getValue0_1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::changeSizeToBig),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createToSmall_getValue_1_2_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createToSmall),
        application.interpretCommand(stub::getValue1_2),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperAmountOfArgsMT, createToBig_getValue_1_2_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createToBig),
        application.interpretCommand(stub::getValue1_2),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

}

