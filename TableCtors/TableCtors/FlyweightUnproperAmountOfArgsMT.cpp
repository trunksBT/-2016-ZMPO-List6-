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
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefm1_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefm1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDef0_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDef0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
// /////////////////////////////////
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_OnEmptyFlyweight_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_createCopy01_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::createCopy01)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_createCopy06_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::createCopy06)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_print0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::print0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_printm1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::printm1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_print6_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::print6)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_print10_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::print10)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_getNamem1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::getNamem1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_getName0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::getName0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs11_getName10_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs11),
//        application.interpretCommand(wrongStub::getName10)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_getSizem1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::getSizem1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_getSize0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::getSize0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_getSize6_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::getSize6)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_getSize10_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::getSize10)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_removem1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::removem1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_remove0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::remove0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_remove0_getName0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::remove0),
//        application.interpretCommand(wrongStub::getName0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_removeAll_getSize6_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::removeAll),
//        application.interpretCommand(wrongStub::getSize6)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setName0_getName0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::setName0),
//        application.interpretCommand(wrongStub::getName0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setName6_getName0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::setName6),
//        application.interpretCommand(wrongStub::getName6)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_setName10_getName0_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::setName10),
//        application.interpretCommand(wrongStub::getName10)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_getValuem1_1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::getValuem1_1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs10_remove0_getValue0_m1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs10),
//        application.interpretCommand(wrongStub::remove0),
//        application.interpretCommand(wrongStub::getValue0_m1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs11_getValue10_10_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs11),
//        application.interpretCommand(wrongStub::getValue10_10)
//    });
//
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setValue0_0_23_getValue0_1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::setValue0_0_23),
//        application.interpretCommand(wrongStub::getValue0_1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_remove0_setValue0_0_23_getValue0_1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::remove0),
//        application.interpretCommand(wrongStub::setValue0_0_23),
//        application.interpretCommand(wrongStub::getValue0_1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setValue10_0_23_getValue0_1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::setValue10_0_23),
//        application.interpretCommand(wrongStub::getValue0_1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setValue10_10_23_getValue0_1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs1),
//        application.interpretCommand(wrongStub::setValue10_10_23),
//        application.interpretCommand(wrongStub::getValue0_1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setValuem1_m1_23_getValue0_1_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs11),
//        application.interpretCommand(wrongStub::setValuem1_m1_23),
//        application.interpretCommand(wrongStub::getValue0_1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}
//
//TEST_F(FlyweightUnproperAmountOfArgsMT, createDefs1_setValue1_m1_23_getValue1_2_Expect_ERROR_COMMAND_PARSING)
//{
//    ERROR_CODE expVal = ERROR_CODE::ERROR_COMMAND_PARSING;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(wrongStub::createDefs11),
//        application.interpretCommand(wrongStub::setValue1_m1_23),
//        application.interpretCommand(wrongStub::getValue1_2)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//    printWrongCommandInfo(std::move(rcVal));
//}

}

