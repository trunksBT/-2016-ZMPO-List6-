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
    CPerson person1 = CPerson("Kowalska", 10);
    CPerson person2 = CPerson("Kowalska", 10);

    ASSERT_EQ(person1, person2);
}

TEST(CPersonTests, CPerson_DefCTOR_onHeap)
{
    CPerson* person1 = new CPerson("Kowalska", 10);
    CPerson* person2 = new CPerson("Kowalska", 10);

    ASSERT_EQ(*person1, *person2);
}

TEST(CPersonTests, CPerson_ParamCTOR_stringCast)
{
    CPerson person1 = CPerson("Kowalska", 10);

    std::cout << std::boolalpha << std::is_trivial<int>::value << std::endl;
    std::cout << std::boolalpha << std::is_trivial<CPerson>::value << std::endl;
//    std::string tempVal = person1;
//    std::cout << tempVal << std::endl;
//    std::cout << std::to_string(10) << std::endl;
//    std::cout << std::string(10.0) << std::endl;

    ASSERT_TRUE(true);
}

TEST(CPersonTests, CPerson_CopyCTOR)
{
    CPerson person1 = CPerson("Kowalska", 10);
    CPerson person2 = CPerson(person1);

    ASSERT_EQ(person1, person2);
}

TEST(CPersonTests, CPerson_CopyAssignement)
{
    CPerson person1 = CPerson("Kowalska", 10);
    CPerson person2 = CPerson("Nowak", 20);
    person1 = person2;

    ASSERT_EQ(person1.getName(), person2.getName());
}

}

