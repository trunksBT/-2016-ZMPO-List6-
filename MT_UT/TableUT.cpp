// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>
#include <ElementsAndTables/CTable.hpp>
#include <Utils/Utils.hpp>
#include <limits>
#include <vector>

using namespace defaultVals;
namespace
{
template<typename T>
class CTableTests : public testing::Test
{
protected:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

using testing::Types;
typedef Types<int, double> Implementations;

TYPED_TEST_CASE_P(CTableTests);

TYPED_TEST_P(CTableTests, defCTOR_getSize_DEFAULTSIZE_Expect_DEFAULTSIZE)
{
   CTable<TypeParam>* inVal = CTable<TypeParam>::buildNewObj();
   TypeParam expVal = TypeParam(5);

   std::size_t rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete inVal;
}

TYPED_TEST_P(CTableTests, defCTOR_getSize_DEFAULTSIZE_Expect_False)
{
    CTable<TypeParam>* inVal = CTable<TypeParam >::buildNewObj();
    TypeParam expVal = 10;

    std::size_t rcVal = inVal->getSize();

    ASSERT_EQ(expVal, rcVal);
    delete inVal;
}

REGISTER_TYPED_TEST_CASE_P(CTableTests,
    defCTOR_getSize_DEFAULTSIZE_Expect_DEFAULTSIZE,
    defCTOR_getSize_DEFAULTSIZE_Expect_False);

typedef ::testing::Types<int, double, unsigned int> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, CTableTests, MyTypes);

//TEST_F(CTableTests, defCTOR_setSize_0_Expect_0)
//{
//   int inSize = ZERO;
//   CTable* inVal = CTable::buildNewObj(inSize);
//   int expVal = ZERO;
//
//   int rcVal = inVal->getSize();
//
//   ASSERT_EQ(expVal, rcVal);
//   delete inVal;
//}
//
//TEST_F(CTableTests, copyCTOR_size5_Expect_size5)
//{
//   int inSize = DEFAULT_IN_TABLE_SIZE;
//   int expVal = DEFAULT_IN_TABLE_SIZE;
//   CTable* sourceVal = CTable::buildNewObj(inSize);
//
//   CTable* inVal = CTable::buildNewObj(*sourceVal);
//   int rcVal = inVal->getSize();
//
//   ASSERT_EQ(expVal, rcVal);
//   delete sourceVal;
//   delete inVal;
//}
//
//TEST_F(CTableTests, copyCTOR_withAssignCopyOperator_size5_Expect_size5)
//{
//   int inSize = FIVE;
//   int expVal = FIVE;
//   CTable* sourceVal = CTable::buildNewObj(inSize);
//
//   CTable* inVal = CTable::buildNewObj();
//   *inVal = *sourceVal;
//
//   int rcVal = inVal->getSize();
//
//   ASSERT_EQ(expVal, rcVal);
//   delete sourceVal;
//   delete inVal;
//}
//
//TEST_F(CTableTests, pushBack_onVector_ofObj_expect_CopyCtor)
//{
//    std::vector<CTable> inVector;
//    inVector.push_back(CTable());
//    inVector.clear();
//    ASSERT_TRUE(true);
//}
//
//TEST_F(CTableTests, setVal_defaultCTORed_3_onIdx_0_Expect_3)
//{
//   int newVal = 500;
//   int idxForNewVal = 0;
//   CTable* sourceVal = CTable::buildNewObj();
//
//   int oldVal = sourceVal->getVal(idxForNewVal);
//   sourceVal->setVal(idxForNewVal, newVal);
//   int rcVal = sourceVal->getVal(idxForNewVal);
//
//   ASSERT_NE(oldVal, rcVal);
//   ASSERT_EQ(newVal, rcVal);
//   delete sourceVal;
//}
//
//TEST_F(CTableTests, getVal_defaultCTORed_3_onIdx_m1_Expect_LimitMin)
//{
//   int idx = -1;
//   CTable* sourceVal = CTable::buildNewObj();
//
//   int rcVal = sourceVal->getVal(idx);
//
//   ASSERT_EQ(std::numeric_limits<int>::min(), rcVal);
//   delete sourceVal;
//}
//
//TEST_F(CTableTests, print_defaultCTORed)
//{
//    CTable* sourceVal = CTable::buildNewObj();
//
//    std::cout << sourceVal->toString();
//
//    ASSERT_TRUE(true);
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, print_Copied)
//{
//    int inSize = FIVE;
//    CTable* sourceVal = CTable::buildNewObj(inSize);
//
//    CTable* inVal = CTable::buildNewObj();
//    *inVal = *sourceVal;
//
//    std::cout << sourceVal->toString() << POST_PRINT;
//    std::cout << inVal->toString() << POST_PRINT;
//
//    ASSERT_TRUE(true);
//    delete inVal;
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, print_Copied_afterSetValue)
//{
//    int inSize = FIVE;
//    CTable* sourceVal = CTable::buildNewObj(inSize);
//
//    CTable* inVal = CTable::buildNewObj();
//    *inVal = *sourceVal;
//    inVal->setVal(ZERO, FIVE);
//
//    std::cout << sourceVal->toString() << POST_PRINT;
//    std::cout << inVal->toString() << POST_PRINT;
//
//    ASSERT_TRUE(true);
//    delete inVal;
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, print_Copied_afterSetName)
//{
//    int inSize = FIVE;
//    CTable* sourceVal = CTable::buildNewObj(inSize);
//
//    CTable* inVal = CTable::buildNewObj();
//    *inVal = *sourceVal;
//    inVal->setName("SIEMA_" + std::string(DEFAULT_TABLE_NAME));
//
//    std::cout << sourceVal->toString() << POST_PRINT;
//    std::cout << inVal->toString() << POST_PRINT;
//
//    ASSERT_TRUE(true);
//    delete inVal;
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, setSize_from_FIVE_onHigher_Expect_TEN)
//{
//    int inSize = FIVE;
//    int newSize = FIVE;
//    int expSize = TEN;
//    int initValue = FIVE;
//    CTable* sourceVal = CTable::buildNewObj(inSize, FIVE);
//
//    std::cout << "Before change size" << std::endl;
//    std::cout << sourceVal->toString() << std::endl;
//
//    sourceVal->setSize(TEN);
//
//    std::cout << "After change size" << std::endl;
//    std::cout << sourceVal->toString() << std::endl;
//
//    ASSERT_EQ(expSize, sourceVal->getSize());
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, setSize_from_FIVE_onLower_Expect_TWO)
//{
//    int inSize = FIVE;
//    int newSize = TWO;
//    int expSize = TWO;
//    int initValue = FIVE;
//    CTable* sourceVal = CTable::buildNewObj(inSize, FIVE);
//
//    std::cout << "Before change size" << std::endl;
//    std::cout << sourceVal->toString() << std::endl;
//
//    sourceVal->setSize(newSize);
//
//    std::cout << "After change size" << std::endl;
//    std::cout << sourceVal->toString() << std::endl;
//
//    ASSERT_EQ(expSize, sourceVal->getSize());
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, setSize_from_FIVE_onTheSame_Expect_FIVE)
//{
//    int inSize = FIVE;
//    int newSize = FIVE;
//    int expSize = FIVE;
//    int initValue = FIVE;
//    CTable* sourceVal = CTable::buildNewObj(inSize, FIVE);
//
//    std::cout << "Before change size" << std::endl;
//    std::cout << sourceVal->toString() << std::endl;
//
//    sourceVal->setSize(newSize);
//
//    std::cout << "After change size" << std::endl;
//    std::cout << sourceVal->toString() << std::endl;
//
//    ASSERT_EQ(expSize, sourceVal->getSize());
//    delete sourceVal;
//}
//
//TEST_F(CTableTests, buildNewObj_FIVE_newName_Expect_FIVE_newName)
//{
//    int inSize = FIVE;
//    std::string inName = "newName";
//    int expSize = FIVE;
//    std::string expName = "newName";
//
//    CTable* sourceVal = CTable::buildNewObj(inSize, inName);
//
//    ASSERT_EQ(expSize, sourceVal->getSize());
//    ASSERT_EQ(expName, sourceVal->getName());
//    delete sourceVal;
//}

}

