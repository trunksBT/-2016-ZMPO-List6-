#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
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

    CPerson(const CPerson&& inObj)
    {
        age_ = std::move(inObj.age_);
        surname_ = std::move(inObj.surname_);
    }

    CPerson& operator=(CPerson&& inObj)
    {
        age_ = std::move(inObj.age_);
        surname_ = std::move(inObj.surname_);
        return *this;
    }

    CPerson(const CPerson& inObj)
        : age_(inObj.age_)
        , surname_(new std::string(*inObj.surname_))
    {
        std::cout << "CPerson COPY_CTOR" << std::endl;
    }

    CPerson& operator=(const CPerson& inObj)
    {
        CPerson temp = inObj;
        swap(*this, temp);
        return *this;
    }

    bool operator==(const CPerson& inObj) const
    {
        return age_ == inObj.age_ && *surname_ == *inObj.surname_;
    }

    ~CPerson()
    {
        std::cout << "CPerson DTOR" << std::endl;
    }

    unsigned int getAge() const noexcept
    {
        return age_;
    }

    explicit operator int()
    {
        return age_;
    }

    std::string getName() const noexcept
    {
        return std::string(*surname_);
    }

    void swap(CPerson& first, CPerson& second)
    {
        using std::swap;
        swap(first.age_, second.age_);
        swap(first.surname_, second.surname_);
    }

private:
    std::string* surname_;
    unsigned int age_;
};
