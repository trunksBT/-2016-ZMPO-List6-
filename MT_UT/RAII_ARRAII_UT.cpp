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

TYPED_TEST_P(RAII_ARRAII_Tests, CopyAssignement)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(new TypeParam(FIVE));
    RAII<TypeParam> tempRAII2 = RAII<TypeParam>(new TypeParam(TEN));
    tempRAII = tempRAII2;

    ASSERT_EQ(tempRAII, tempRAII2);
}

TYPED_TEST_P(RAII_ARRAII_Tests, CopyCtor)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(new TypeParam(FIVE));
    RAII<TypeParam> tempRAII2 = RAII<TypeParam>(RAII<TypeParam>(new TypeParam(FIVE)));

    ASSERT_EQ(tempRAII, tempRAII2);
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

REGISTER_TYPED_TEST_CASE_P(RAII_ARRAII_Tests,
    CopyAssignement,
    CopyCtor);

typedef ::testing::Types<int, double, unsigned int, CPerson> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, RAII_ARRAII_Tests, MyTypes);

}
