// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>
#include <ElementsAndTables/CTable.hpp>
#include <ElementsAndTables/Person.hpp>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>
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

TYPED_TEST_CASE_P(CTableTests);

TYPED_TEST_P(CTableTests, tableOfTables_operatorOstream)
{
    CTable<CTable<TypeParam>> tempRAII3 = CTable<CTable<TypeParam>>(8);
    logger << static_cast<std::string>(tempRAII3) << POST_PRINT;

    ASSERT_EQ(tempRAII3[0].getSize(), tempRAII3.getSize());
}

TYPED_TEST_P(CTableTests, copyCTOR_getSize)
{
    CTable<CTable<TypeParam>>* inVal = CTable<CTable<TypeParam>>::buildNewObj(TEN);
    CTable<CTable<TypeParam>>* copyOfInInVal = CTable<CTable<TypeParam>>::buildNewObj(inVal);

    ASSERT_EQ(TEN, inVal->getSize());
    ASSERT_EQ(*inVal, *copyOfInInVal);
    delete inVal;
    delete copyOfInInVal;
}

TYPED_TEST_P(CTableTests, copyAssignement_getSize)
{
    CTable<CTable<TypeParam>>* inVal = CTable<CTable<TypeParam>>::buildNewObj(TEN);
    CTable<CTable<TypeParam>> copyOfInInVal = *CTable<CTable<TypeParam>>::buildNewObj(FIVE);
    copyOfInInVal = *inVal;

    ASSERT_EQ(*inVal, copyOfInInVal);
    ASSERT_EQ(inVal->getSize(), copyOfInInVal.getSize());
    delete inVal;
}

TYPED_TEST_P(CTableTests, setValue_getValue_10)
{
    CTable<CTable<TypeParam>>* inVal = CTable<CTable<TypeParam>>::buildNewObj(TEN);
    CTable<TypeParam> newValue = CTable<TypeParam>(TEN);
    int idx = ZERO;

    inVal->setVal(idx, newValue);
    CTable<TypeParam> rcVal = inVal->getVal(idx);

    ASSERT_EQ(newValue, rcVal);
    delete inVal;
}

TYPED_TEST_P(CTableTests, setSize_5)
{
    CTable<CTable<TypeParam>>* inVal = CTable<CTable<TypeParam>>::buildNewObj(TEN);

    inVal->setSize(FIVE);

    ASSERT_EQ(FIVE, inVal->getSize());
    delete inVal;
}

REGISTER_TYPED_TEST_CASE_P(CTableTests,
    copyCTOR_getSize,
    tableOfTables_operatorOstream,
    copyAssignement_getSize,
    setValue_getValue_10,
    setSize_5
    );

typedef ::testing::Types<int, double, unsigned int, CPerson> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, CTableTests, MyTypes);

}
