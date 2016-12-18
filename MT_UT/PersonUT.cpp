// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>
#include <ElementsAndTables/Person.hpp>
#include <sstream>
#include <Utils/Utils.hpp>
#include <limits>
#include <type_traits>
#include <vector>

using namespace defaultVals;
namespace
{
template<typename T>
class CPersonTests : public testing::Test
{
protected:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

TEST(CPersonTests, CPerson_DefCTOR)
{
    CPerson person1 = CPerson(DEFAULT_SURNAME, TEN);
    CPerson person2 = CPerson(DEFAULT_SURNAME, TEN);

    ASSERT_EQ(person1, person2);
}

TEST(CPersonTests, CPerson_ParamCTOR_stringCast)
{
    CPerson person1 = CPerson(DEFAULT_SURNAME, TEN);

    std::cout << person1 << std::endl; 

    ASSERT_TRUE(true);
}

TEST(CPersonTests, CPerson_CopyCTOR)
{
    CPerson person1 = CPerson(DEFAULT_SURNAME, TEN);
    CPerson person2 = person1;

    ASSERT_EQ(person1, person2);
}

TEST(CPersonTests, CPerson_CopyAssignement)
{
    CPerson person1 = CPerson(DEFAULT_SURNAME, TEN);
    CPerson person2 = CPerson(OTHER_SURNAME, FIVE);
    person1 = person2;

    ASSERT_EQ(person1, person2);
}

TEST(CPersonTests, CPerson_MoveCTOR)
{
    CPerson person1 = CPerson(DEFAULT_SURNAME, TEN);
    CPerson person2 = CPerson(CPerson(DEFAULT_SURNAME, TEN));

    ASSERT_EQ(person1, person2);
}

TEST(CPersonTests, CPerson_MoveAssignement)
{
    CPerson person1 = CPerson(DEFAULT_SURNAME, TEN);
    person1 = CPerson(DEFAULT_SURNAME, TEN);

    ASSERT_EQ(CPerson(DEFAULT_SURNAME, TEN), person1);
}
}

