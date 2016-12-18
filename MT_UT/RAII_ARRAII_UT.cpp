// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>
#include <ElementsAndTables/CTable.hpp>
#include <ElementsAndTables/Person.hpp>
#include <Utils/Utils.hpp>
#include <limits>
#include <vector>

using namespace defaultVals;
namespace
{
template<typename T>
class RAII_ARRAII_Tests : public testing::Test
{
protected:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

using testing::Types;

TYPED_TEST_CASE_P(RAII_ARRAII_Tests);

TYPED_TEST_P(RAII_ARRAII_Tests, RAII_Int)
{
    TypeParam initVal = FIVE;
    RAII<TypeParam> tempRAII = RAII<TypeParam>(initVal);
    RAII<int> tempRAII2 = RAII<int>(TEN);
    tempRAII = tempRAII2;

    ASSERT_EQ(3, 3);
}

//TYPED_TEST_CASE_P(RAII_ARRAII_Tests, paramCTOR_Int_castToString)
//{
//    std::cout << "SIEMA" << std::endl;
//    ARRAII<int> tempRAII = ARRAII<int>(TWO);
//    ARRAII<CPerson> tempRAII2 = ARRAII<CPerson>(TWO);
//
//    std::cout << static_cast<std::string>(tempRAII) << std::endl;
//    std::cout << static_cast<std::string>(tempRAII2) << std::endl;
//
//    ASSERT_TRUE(true);
//}
//
//REGISTER_TYPED_TEST_CASE_P(RAII_ARRAII_Tests,
//    defCTOR_getSize,
//    copyCTOR_getSize,
//    defCTOR_setValue_getValue_10
//    );
//
//typedef ::testing::Types<int, double, unsigned int, CPerson> MyTypes;
//INSTANTIATE_TYPED_TEST_CASE_P(My, RAII_ARRAII_Tests, MyTypes);

}
