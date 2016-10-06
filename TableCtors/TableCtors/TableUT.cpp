#include "stdafx.h"
#include <gtest/gtest.h>
#include "CTable.hpp"
#include "Utils.hpp"

using namespace defaultVals;
namespace
{
class CTableTests : public testing::Test
{
protected:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

//Test_MethodName_StateUnderTest_Expect_ExpectedBehavior
TEST_F(CTableTests, defCTOR_getSize_DEFAULTSIZE_Expect_DEFAULTSIZE)
{
   CTable* inVal = new CTable();
   int expVal = DEFAULT_IN_TABLE_SIZE;

   int rcVal = inVal->getSize();

   EXPECT_EQ(expVal, rcVal);
   delete inVal;
}
}

