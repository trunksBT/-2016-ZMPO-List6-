#include "Person.hpp"

#include <algorithm>
#include <sstream>
#include <utility>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace flags;

 CPerson::CPerson(int inAge) noexcept
    : surname_(RAII<std::string>(DEFAULT_SURNAME))
    , age_(inAge)
{
     if (PRINT_ERRORS)
     {
        logger << "CPerson CTOR" << POST_PRINT;
     }
}

CPerson::CPerson(std::string inSurname, unsigned int inAge) noexcept
    : surname_(RAII<std::string>(inSurname))
    , age_(inAge)
{
    if (PRINT_ERRORS)
    {
        logger << "CPerson CTOR" << POST_PRINT;
    }
}

CPerson::CPerson(const CPerson& inObj) noexcept
    : age_(inObj.age_)
    , surname_(inObj.surname_)
{
    if (PRINT_ERRORS)
    {
        logger << "CPerson COPY_CTOR" << POST_PRINT;
    }
}

CPerson::CPerson(CPerson&& inObj) noexcept
    : surname_(std::move(inObj.surname_))
    , age_(std::move(inObj.age_))
{
    if (PRINT_ERRORS)
    {
        logger << "CPerson MoveCTOR" << POST_PRINT;
    }
}

CPerson& CPerson::operator=(CPerson&& inObj) noexcept
{
    swap(*this, inObj);
    if (PRINT_ERRORS)
    {
        logger << "CPerson Move=" << POST_PRINT;
    }
    return *this;
}

CPerson& CPerson::operator=(const CPerson& inObj) noexcept
{
    CPerson temp{ CPerson(inObj) };
    swap(*this, temp);
    if (PRINT_ERRORS)
    {
        logger << "CPerson COPY=" << POST_PRINT;
    }
    return *this;
}

bool CPerson::operator==(const CPerson& inObj) const noexcept
{
    return age_ == inObj.age_ && surname_ == inObj.surname_;
}

CPerson::~CPerson() noexcept
{
    if (PRINT_ERRORS)
    {
        logger << "CPerson DTOR" << POST_PRINT;
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
