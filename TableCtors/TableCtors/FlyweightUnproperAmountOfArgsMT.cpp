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
class CFlyweightUnproperAmountOfArgsMT : public testing::Test
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

TEST_F(CFlyweightUnproperAmountOfArgsMT, createDefToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, createDefToBig_OnEmptyCFlyweight_Expect_ERROR_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, createDefsToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefsToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, createDefsToBig_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createDefsToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, createCopy0ToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createCopy0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, createCopy0ToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::createCopy0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, printToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::printToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, printToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::printToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getNameToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getNameToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getNameToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getNameToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getSizeToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getSizeToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getSizeToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getSizeToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, deleteToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::deleteToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, deleteToBig_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::deleteToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, deleteAllToBig_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::deleteAllToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, setName0ToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setName0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, setName0ToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setName0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getValue0ToToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getValue0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getValue0ToToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getValue0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, getValueToBig_1_23_3_4_5_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::getValueToBig_1_23_3_4_5)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, setValue0_0ToSmall_OnEmptyCFlyweight_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setValue0_0ToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, setValue0_0ToBig_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setValue0_0ToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, wrongCommandToSmall_OnEmptyCFlyweight_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::wrongCommandToSmall)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, wrongCommandToBig_OnEmptyCFlyweight_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::wrongCommandToBig)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, setSizeToSmall_getValue0_1_Expect_WRONG_AMOUNT_OF_ARGS)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setSizeToSmall),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, setSizeToBig_getValue0_1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongAmountStub::setSizeToBig),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightUnproperAmountOfArgsMT, createToSmall_getValue_1_2_Expect_WRONG_AMOUNT_OF_ARGS)
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

TEST_F(CFlyweightUnproperAmountOfArgsMT, createToBig_getValue_1_2_Expect_SEEMS_LEGIT)
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

