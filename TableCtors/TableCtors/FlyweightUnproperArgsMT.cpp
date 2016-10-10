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
class FlyweightUnproperArgsMT : public testing::Test
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

TEST_F(FlyweightUnproperArgsMT, createDefs1_wrongCommand_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs11),
        application.interpretCommand(wrongStub::wrongCommand),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, getFinalResultCode_createDef_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDef0),
        application.interpretCommand(wrongStub::createDef0),
        application.interpretCommand(wrongStub::createDef0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, getFinalResultCode_createDef_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDef0),
        application.interpretCommand(wrongStub::createDefm1),
        application.interpretCommand(wrongStub::createDef0)
    });

    ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
}

TEST_F(FlyweightUnproperArgsMT, createDefm1_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDef0_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDef0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDef6_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDef6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs6_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_createCopy01_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::createCopy01)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_createCopy06_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::createCopy06)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_print0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::print0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_printm1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::printm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_print6_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::print6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_print10_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::print10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_getNamem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::getNamem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs11_getName10_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs11),
        application.interpretCommand(wrongStub::getName10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_getSizem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::getSizem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_getSize0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::getSize0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_getSize6_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::getSize6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_getSize10_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::getSize10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_remove0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::remove0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_remove0_getName0_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::remove0),
        application.interpretCommand(wrongStub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_removeAll_getSize6_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::removeAll),
        application.interpretCommand(wrongStub::getSize6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_setName0_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::setName0),
        application.interpretCommand(wrongStub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_setName6_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::setName6),
        application.interpretCommand(wrongStub::getName6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_setName10_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::setName10),
        application.interpretCommand(wrongStub::getName10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_getValuem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::getValuem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs10_remove0_getValuem1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs10),
        application.interpretCommand(wrongStub::remove0),
        application.interpretCommand(wrongStub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs11_getValue10_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs11),
        application.interpretCommand(wrongStub::getValue10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_setValue0_0_23_getValue0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::setValue0_0_23),
        application.interpretCommand(wrongStub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_remove0_setValue0_0_23_getValue0_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::remove0),
        application.interpretCommand(wrongStub::setValue0_0_23),
        application.interpretCommand(wrongStub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_setValue10_0_23_getValue0_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs1),
        application.interpretCommand(wrongStub::setValue10_0_23),
        application.interpretCommand(wrongStub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_setValue10_10_23_getValue0_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs11),
        application.interpretCommand(wrongStub::setValue10_10_23),
        application.interpretCommand(wrongStub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(FlyweightUnproperArgsMT, createDefs1_setValuem1_m1_23_getValue0_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs11),
        application.interpretCommand(wrongStub::setValuem1_m1_23),
        application.interpretCommand(wrongStub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightUnproperArgsMT, createDefs1_setValue1_m1_23_getValue1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongStub::createDefs11),
        application.interpretCommand(wrongStub::setValue1_m1_23),
        application.interpretCommand(wrongStub::getValue1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

}

