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

TYPED_TEST_P(RAII_ARRAII_Tests, Ctor_y_OperatorBool)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(TypeParam(FIVE));

    ASSERT_TRUE(tempRAII);
}

TYPED_TEST_P(RAII_ARRAII_Tests, RAII_CopyCtor)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(TypeParam(FIVE));
    RAII<TypeParam> tempRAII2 = RAII<TypeParam>(tempRAII);

    ASSERT_EQ(tempRAII, tempRAII2);
}

TYPED_TEST_P(RAII_ARRAII_Tests, RAII_CopyAssignement)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(TypeParam(FIVE));
    RAII<TypeParam> tempRAII2 = RAII<TypeParam>(TypeParam(TEN));
    tempRAII = tempRAII2;

    ASSERT_EQ(tempRAII, tempRAII2);
}

TYPED_TEST_P(RAII_ARRAII_Tests, RAII_MoveCtor)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(TypeParam(FIVE));
    RAII<TypeParam> tempRAII2 = RAII<TypeParam>(RAII<TypeParam>(TypeParam(FIVE)));

    ASSERT_EQ(tempRAII, tempRAII2);
}

TYPED_TEST_P(RAII_ARRAII_Tests, RAII_MoveAssignement)
{
    RAII<TypeParam> tempRAII = RAII<TypeParam>(TypeParam(TEN));
    tempRAII = RAII<TypeParam>(RAII<TypeParam>(TypeParam(FIVE)));

    ASSERT_EQ(RAII<TypeParam>(RAII<TypeParam>(TypeParam(FIVE))), tempRAII);
}

TYPED_TEST_P(RAII_ARRAII_Tests, ARRAII_CopyCtor)
{
    ARRAII<TypeParam> tempRAII = ARRAII<TypeParam>(FIVE);
    ARRAII<TypeParam> tempRAII2 = ARRAII<TypeParam>(tempRAII);

    ASSERT_EQ(tempRAII, tempRAII2);
}

TYPED_TEST_P(RAII_ARRAII_Tests, ARRAII_CopyAssignement)
{
    ARRAII<TypeParam> tempRAII = ARRAII<TypeParam>(FIVE);
    ARRAII<TypeParam> tempRAII2 = ARRAII<TypeParam>(TEN);
    tempRAII = tempRAII2;

    ASSERT_EQ(tempRAII, tempRAII2);
}

TYPED_TEST_P(RAII_ARRAII_Tests, ARRAII_MoveCtor)
{
    ARRAII<TypeParam> tempRAII = ARRAII<TypeParam>(ARRAII<TypeParam>(FIVE));

    ASSERT_EQ(ARRAII<TypeParam>(FIVE), tempRAII);
}

TYPED_TEST_P(RAII_ARRAII_Tests, ARRAII_MoveAssignement)
{
    ARRAII<TypeParam> tempRAII = ARRAII<TypeParam>(TEN);
    tempRAII = ARRAII<TypeParam>(ARRAII<TypeParam>(FIVE));

    ASSERT_EQ(ARRAII<TypeParam>(FIVE), tempRAII);
}

TYPED_TEST_P(RAII_ARRAII_Tests, ARRAII_EqOperator)
{
    ARRAII<TypeParam> tempRAII = ARRAII<TypeParam>(TEN);
    ARRAII<TypeParam> tempRAII2 = ARRAII<TypeParam>(FIVE);

    ASSERT_FALSE(tempRAII == tempRAII2);
}

REGISTER_TYPED_TEST_CASE_P(RAII_ARRAII_Tests,
    Ctor_y_OperatorBool,
    RAII_CopyCtor,
    RAII_CopyAssignement,
    RAII_MoveCtor,
    RAII_MoveAssignement,
    ARRAII_CopyCtor,
    ARRAII_CopyAssignement,
    ARRAII_MoveCtor,
    ARRAII_MoveAssignement,
    ARRAII_EqOperator
);

typedef ::testing::Types<int, double, unsigned int, CPerson> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, RAII_ARRAII_Tests, MyTypes);

}
