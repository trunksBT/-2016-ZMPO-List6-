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
    class List1 : public testing::Test
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

        std::vector<std::string> createDef2 = { "createDef", "2" };
        std::vector<std::string> setName2Def = { "setName", "2", "def" };
        std::vector<std::string> create1_11_one = { "create", "1" , "11", "one" };
        std::vector<std::string> setValue_2_3_8 = { "setValue", "2" , "3", "8" };
        std::vector<std::string> createCopy_3_2 = { "createCopy", "3" , "2" };
        std::vector<std::string> setValue_3_3_0 = { "setValue", "3" , "3", "0" };
        std::vector<std::string> setSize_3_20 = { "setSize", "3" , "20" };
        std::vector<std::string> getValue_1_3 = { "getValue", "1" , "3" };
        std::vector<std::string> getValue_2_3 = { "getValue", "2" , "3" };
        std::vector<std::string> getValue_3_3 = { "getValue", "3" , "3" };
        std::vector<std::string> delete_2 = { "delete", "2" };
        std::vector<std::string> clear_3 = { "clear", "3" };
    };

    TEST_F(List1, 
        to1_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to2_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to3_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to4_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to5_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2)
         });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to6_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setValue_3_3_0),
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to7_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to8_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20),
            application.interpretCommand(getValue_1_3)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to9_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20),
            application.interpretCommand(getValue_1_3),
            application.interpretCommand(getValue_2_3)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to10_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20),
            application.interpretCommand(getValue_1_3),
            application.interpretCommand(getValue_2_3),
            application.interpretCommand(getValue_3_3)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to11_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20),
            application.interpretCommand(getValue_1_3),
            application.interpretCommand(getValue_2_3),
            application.interpretCommand(getValue_3_3),
            application.interpretCommand(delete_2)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to12_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20),
            application.interpretCommand(getValue_1_3),
            application.interpretCommand(getValue_2_3),
            application.interpretCommand(getValue_3_3),
            application.interpretCommand(delete_2),
            application.interpretCommand(clear_3)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }

    TEST_F(List1,
        to13_SEEMS_LEGIT)
    {
        ERROR_CODE expVal = ERROR_CODE::SEEMS_LEGIT;

        rcVal = getFinalResultCode
        ({
            application.interpretCommand(createDef2),
            application.interpretCommand(setName2Def),
            application.interpretCommand(create1_11_one),
            application.interpretCommand(setValue_2_3_8),
            application.interpretCommand(createCopy_3_2),
            application.interpretCommand(setSize_3_20),
            application.interpretCommand(getValue_1_3),
            application.interpretCommand(getValue_2_3),
            application.interpretCommand(getValue_3_3),
            application.interpretCommand(delete_2),
            application.interpretCommand(clear_3),
            application.interpretCommand(getValue_3_3)
        });

        ASSERT_FOR_PAIR_WITH_PRINT(expVal, rcVal);
    }
}
