#include "Person.hpp"

#include <algorithm>
#include <sstream>
#include <utility>
#include <Utils/Utils.hpp>

using namespace defaultVals;

 CPerson::CPerson(int inAge) noexcept
    : surname_(RAII<std::string>(DEFAULT_SURNAME))
    , age_(inAge)
{
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson CTOR" << std::endl;
    }
}

CPerson::CPerson(std::string inSurname, unsigned int inAge) noexcept
    : surname_(RAII<std::string>(inSurname))
    , age_(inAge)
{
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson CTOR" << std::endl;
    }
}

CPerson::CPerson(const CPerson& inObj) noexcept
    : age_(inObj.age_)
    , surname_(inObj.surname_)
{
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson COPY_CTOR" << std::endl;
    }
}

CPerson::CPerson(CPerson&& inObj) noexcept
    : surname_(std::move(inObj.surname_))
    , age_(std::move(inObj.age_))
{
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson MoveCTOR" << std::endl;
    }
}

CPerson& CPerson::operator=(CPerson&& inObj) noexcept
{
    swap(*this, inObj);
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson Move=" << std::endl;
    }
    return *this;
}

CPerson& CPerson::operator=(const CPerson& inObj) noexcept
{
    CPerson temp{ CPerson(inObj) };
    swap(*this, temp);
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson COPY=" << std::endl;
    }
    return *this;
}

bool CPerson::operator==(const CPerson& inObj) const noexcept
{
    return age_ == inObj.age_ && surname_ == inObj.surname_;
}

CPerson::~CPerson() noexcept
{
    if (flag::PRINT_ON)
    {
        std::cout << "CPerson DTOR" << std::endl;
    }
}

CPerson::operator std::string() const noexcept
{
    std::stringstream retVal;
    retVal << BRACKET_OPEN << SURNAME << SEPARATOR << getName();
    retVal << COMMA_SPACE << AGE << SEPARATOR << age_ << BRACKET_CLOSE << POST_PRINT;
    return std::move(retVal.str());
}

std::string CPerson::getName() const noexcept
{
    return *surname_;
}

void CPerson::swap(CPerson& first, CPerson& second) noexcept
{
    std::swap(first.age_, second.age_);
    RAII<std::string>::swap(first.surname_, second.surname_);
}
