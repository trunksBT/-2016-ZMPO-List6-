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
    CPerson(int inAge)
        : surname_(new std::string(DEFAULT_SURNAME))
        , age_(inAge)
    {
        std::cout << "CPerson CTOR" << std::endl;
    }

    CPerson(std::string inSurname = DEFAULT_SURNAME, unsigned int inAge = FIVE)
        : surname_(new std::string(inSurname))
        , age_(inAge)
    {
        std::cout << "CPerson CTOR" << std::endl;
    }

    CPerson(const CPerson& inObj)
        : age_(inObj.age_)
        , surname_(inObj.surname_)
    {
        std::cout << "CPerson COPY_CTOR" << std::endl;
    }

    CPerson& operator=(const CPerson& inObj)
    {
        CPerson temp = inObj;
        swap(*this, temp);
        return *this;
    }

    bool operator==(const CPerson& inObj) const noexcept
    {
        return age_ == inObj.age_ && surname_ == inObj.surname_;
    }

    ~CPerson()
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

    operator std::string() const noexcept
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
