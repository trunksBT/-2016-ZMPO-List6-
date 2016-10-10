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
class FlyweightProperArgsMT : public testing::Test
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

TEST_F(FlyweightProperArgsMT, getFinalResultCode_createDef_Expect_SEEMS_LEGIT)
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

TEST_F(FlyweightProperArgsMT, getFinalResultCode_createDef_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(FlyweightProperArgsMT, createDefm1_OnEmptyFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
    
    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDef0_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDef0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDef6_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDef6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs6_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_OnEmptyFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_createCopy01_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::createCopy01)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_createCopy06_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::createCopy06)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_print0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::print0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_printm1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::printm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_print6_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::print6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_print10_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::print10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_getNamem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getNamem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs11_getName10_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::getName10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_getSizem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::getSizem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_getSize0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::getSize0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_getSize6_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getSize6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_getSize10_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getSize10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_remove0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::remove0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_remove0_getName0_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::remove0),
        application.interpretCommand(stub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_removeAll_getSize6_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::removeAll),
        application.interpretCommand(stub::getSize6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_setName0_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setName0),
        application.interpretCommand(stub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_setName6_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setName6),
        application.interpretCommand(stub::getName6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_setName10_getName0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::setName10),
        application.interpretCommand(stub::getName10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_getValuem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getValuem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs10_remove0_getValuem1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::remove0),
        application.interpretCommand(stub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs11_getValue10_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::getValue10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_setValue0_0_23_getValue0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setValue0_0_23),
        application.interpretCommand(stub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_remove0_setValue0_0_23_getValue0_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::remove0),
        application.interpretCommand(stub::setValue0_0_23),
        application.interpretCommand(stub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_setValue10_0_23_getValue0_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setValue10_0_23),
        application.interpretCommand(stub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_setValue10_10_23_getValue0_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setValue10_10_23),
        application.interpretCommand(stub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(FlyweightProperArgsMT, createDefs1_setValuem1_m1_23_getValue0_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setValuem1_m1_23),
        application.interpretCommand(stub::getValue0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(FlyweightProperArgsMT, createDefs1_setValue1_m1_23_getValue1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setValue1_m1_23),
        application.interpretCommand(stub::getValue1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

}

