// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>
#include <ElementsAndTables/CTable.hpp>
#include <ElementsAndTables/Person.hpp>
#include <boost/optional.hpp>
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

TEST(CTableTests, RAII_Int)
{
    RAII<int> tempRAII = RAII<int>(new int(FIVE));
    RAII<int> tempRAII2 = RAII<int>(new int(TEN));
    tempRAII = tempRAII2;

    ASSERT_EQ(tempRAII, tempRAII2);
}

TEST(CTableTests, paramCTOR_Int_castToString)
{
    std::cout << "SIEMA" << std::endl;
    ARRAII<int> tempRAII = ARRAII<int>(TWO);
    ARRAII<CPerson> tempRAII2 = ARRAII<CPerson>(TWO);

    std::cout << static_cast<std::string>(tempRAII) << std::endl;
    std::cout << static_cast<std::string>(tempRAII2) << std::endl;

    ASSERT_TRUE(true);
}

TEST(CTableTests, WrapInWrap)
{
    CTable<CTable<int>> tempRAII3 = CTable<CTable<int>>(8);
    std::cout << tempRAII3[0].getSize() << "\n";
    std::cout << tempRAII3.getSize() << "\n";

    //std::cout << tempRAII3 << std::endl;
    //tempRAII3[1][2] = 9;
    //std::cout << tempRAII3[1] << std::endl;


    ASSERT_TRUE(true);
}

TYPED_TEST_P(CTableTests, defCTOR_getSize)
{
    CTable<TypeParam>* inVal = CTable<TypeParam>::buildNewObj();

    ASSERT_EQ(FIVE, inVal->getSize());
    delete inVal;
}

TYPED_TEST_P(CTableTests, copyCTOR_getSize)
{
    CTable<TypeParam>* inVal = CTable<TypeParam>::buildNewObj(TEN);
    CTable<TypeParam>* copyOfInInVal = CTable<TypeParam>::buildNewObj(inVal);

    ASSERT_EQ(TEN, inVal->getSize());
    delete inVal;
}

//TYPED_TEST_P(CTableTests, copyAssignement_getSize)
//{
//
//    CTable<TypeParam>* inVal = CTable<TypeParam>::buildNewObj(TEN);
//    //CTable<TypeParam> copyOfInInVal;
//    copyOfInInVal = *inVal;
//
//    ASSERT_EQ(*inVal, copyOfInInVal);
//    delete inVal;
//}

TYPED_TEST_P(CTableTests, defCTOR_setValue_getValue_10)
{
    CTable<TypeParam>* inVal = CTable<TypeParam>::buildNewObj();
    TypeParam newValue = TypeParam(TEN);
    int idx = ZERO;

    inVal->setVal(idx, newValue);
    TypeParam rcVal = inVal->getVal(idx);

    ASSERT_EQ(newValue, rcVal);
    delete inVal;
}

REGISTER_TYPED_TEST_CASE_P(CTableTests,
    defCTOR_getSize,
    copyCTOR_getSize,
    //copyAssignement_getSize,
    defCTOR_setValue_getValue_10
    );

typedef ::testing::Types<int, double, unsigned int
    , CPerson
> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, CTableTests, MyTypes);

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

