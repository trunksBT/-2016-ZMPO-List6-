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
class CFlyweightProperArgsMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = std::make_pair(MINUS_ONE, ERROR_CODE::INITIAL_VAL);
    }

    virtual void TearDown()
    {}
protected:
    CFlyweight application;
    ResultCode rcVal;
};

TEST_F(CFlyweightProperArgsMT, getFinalResultCode_createDef_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, emptyCommand_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::emptyCommand)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, noCommand_Expect_ERROR_COMMAND_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::noCommand)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));

}

TEST_F(CFlyweightProperArgsMT, getFinalResultCode_createDef_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, create1_5_Name_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::create1_5_Name)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, create1_m5_Name_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::create1_m5_Name)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createm1_5_Name_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createm1_5_Name)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, create6_5_Name_Name_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::create6_5_Name)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefm1_OnEmptyCFlyweight_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
    
    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDef0_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDef0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDef6_OnEmptyCFlyweight_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDef6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefsm1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefsm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs0_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs6_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_createCopym1_m1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::createCopym1_m1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createCopy01_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createCopy10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_createCopy00_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::createCopy00)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_createCopy01_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::createCopy10)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_createCopy0_m1_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::createCopym1_0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_createCopy06_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::createCopy60)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, print_OnEmptyCFlyweight_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::print0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_print0_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_printm1_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_print6_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs10_print10_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs10_m1_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getNamem)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_getNamem1_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_getName0_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, createDefs11_getName10_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_getSizem1_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_getSize0_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, createDefs10_getSize6_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, createDefs10_getSize10_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_deletem1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::deletem1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_delete0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::delete0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_delete0_getName0_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::delete0),
        application.interpretCommand(stub::getName0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_deleteAll_getSize6_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::deleteAll),
        application.interpretCommand(stub::getSize6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, deleteAll_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::deleteAll)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(CFlyweightProperArgsMT, getName99999999999999999999999_Expect_ERROR_ARGS_PARSING)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR_ARGS_PARSING;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::getName99999999999999999999999)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(CFlyweightProperArgsMT, createDefs1_setName0_getName0_Expect_SEEMS_LEGIT)
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

TEST_F(CFlyweightProperArgsMT, createDefs1_setName6_getName0_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs10_setName10_getName0_Expect_INDEX_OUT_OF_BOUNDS)
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

TEST_F(CFlyweightProperArgsMT, createDefs10_getValuem1_1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getValuem1_1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_delete0_getValue0_m1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::delete0),
        application.interpretCommand(stub::getValue0_m1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_getValue1_0_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::getValue1_0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs11_getValue10_10_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::getValue10_10)
    });


    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_setValue0_0_23_getValue0_1_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setValue0_0_23),
        application.interpretCommand(stub::getValue0_1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_delete0_setValue0_0_23_getValue0_1_Expect_UNDEFINED_OBJECT)
{
    ERROR_CODE expVal = ERROR_CODE::UNDEFINED_OBJECT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::delete0),
        application.interpretCommand(stub::setValue0_0_23),
        application.interpretCommand(stub::getValue0_1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_setValue10_0_23_getValue0_1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setValue10_0_23),
        application.interpretCommand(stub::getValue0_1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_setValue10_10_23_getValue0_1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1),
        application.interpretCommand(stub::setValue10_10_23),
        application.interpretCommand(stub::getValue0_1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}


TEST_F(CFlyweightProperArgsMT, createDefs1_setValuem1_m1_23_getValue0_1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setValuem1_m1_23),
        application.interpretCommand(stub::getValue0_1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs11_setValue1_m1_23_getValue1_2_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setValue1_m1_23),
        application.interpretCommand(stub::getValue1_2)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs11_setSize_0_5_getValue0_1_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setSize_0_5),
        application.interpretCommand(stub::getValue0_1),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs11_setSize_m1_5_getValue0_1_Expect_INDEX_OUT_OF_BOUNDS)
{
    ERROR_CODE expVal = ERROR_CODE::INDEX_OUT_OF_BOUNDS;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setSize_m1_5),
        application.interpretCommand(stub::getValue0_1),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs11_setSize_0_m5_getValue0_1_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs11),
        application.interpretCommand(stub::setSize_0_m5),
        application.interpretCommand(stub::getValue0_1),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, setSize_0_m5_getValue0_1_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::WRONG_VALUE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::setSize_0_m5),
        application.interpretCommand(stub::getValue0_1),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, printAll_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::printAll),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs10_printAll_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs10),
        application.interpretCommand(stub::printAll),
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

TEST_F(CFlyweightProperArgsMT, help_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::help)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
    printWrongCommandInfo(std::move(rcVal));
}

}

