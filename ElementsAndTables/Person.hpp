#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <ElementsAndTables/RAII.hpp>
#include <Utils/Utils.hpp>

using namespace defaultVals;
class CPerson
{
public:
    explicit CPerson(int inAge) noexcept
        : surname_(RAII<std::string>(DEFAULT_SURNAME))
        , age_(inAge)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "CPerson CTOR" << std::endl;
        }
    }

    CPerson(std::string inSurname ,unsigned int inAge) noexcept
        : surname_(RAII<std::string>(inSurname))
        , age_(inAge)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "CPerson CTOR" << std::endl;
        }
    }

    CPerson(const CPerson& inObj) noexcept
        : age_(inObj.age_)
        , surname_(inObj.surname_)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "CPerson COPY_CTOR" << std::endl;
        }
    }

    CPerson(CPerson&& inObj) noexcept
        : surname_(std::move(inObj.surname_))
        , age_(std::move(inObj.age_))
    {
        if (flag::PRINT_ON)
        {
            std::cout << "CPerson MoveCTOR" << std::endl;
        }
    }

    CPerson& operator=(CPerson&& inObj) noexcept
    {
        swap(*this, inObj);
        if (flag::PRINT_ON)
        {
            std::cout << "CPerson Move=" << std::endl;
        }
        return *this;
    }

    CPerson& operator=(const CPerson& inObj) noexcept
    {
        CPerson temp{ CPerson(inObj) };
        swap(*this, temp);
        if (flag::PRINT_ON)
        {
            std::cout << "CPerson COPY=" << std::endl;
        }
        return *this;
    }

    bool operator==(const CPerson& inObj) const noexcept
    {
        return age_ == inObj.age_ && surname_ == inObj.surname_;
    }

    ~CPerson() noexcept
    {
        std::cout << "CPerson DTOR" << std::endl;
    }

    unsigned int getAge() const noexcept
    {
        return age_;
    }

    explicit operator int() const noexcept
    {
        return age_;
    }

    friend std::ostream& operator<<(std::ostream& stream, const CPerson& inVal)
    {
        stream<<static_cast<std::string>(inVal);
        return stream;
    }

   explicit operator std::string() const noexcept
    {
        std::stringstream retVal;
        retVal << BRACKET_OPEN << SURNAME << SEPARATOR << getName();
        retVal << COMMA_SPACE << AGE << SEPARATOR << age_ << BRACKET_CLOSE << POST_PRINT;
        return std::move(retVal.str());
    }

    std::string getName() const noexcept
    {
        return *surname_;
    }

    void swap(CPerson& first, CPerson& second) noexcept
    {
        std::swap(first.age_, second.age_);
        RAII<std::string>::swap(first.surname_, second.surname_);
    }

private:
    RAII<std::string> surname_;
    unsigned int age_;
};
