#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <Utils/Utils.hpp>
#include <ElementsAndTables/ARRAII.hpp>

using namespace defaultVals;
using namespace funs;

template<typename T>
class CTable
{
public:
    CTable(size_t size = DEFAULT_IN_TABLE_SIZE)
        : memory_(ARRAII<T>(size))
    {
        if (flag::PRINT_ON)
        {
            std::cout << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    CTable(const CTable& inVal)
        : name_(inVal.name_)
        , memory_(inVal.memory_)
    {
        if (flag::PRINT_ON)
        {
            std::cout << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    CTable<T>& operator=(const CTable& inObj) 
    {
        CTable<T> temp = inObj;
        swap(*this, temp);
        if (flag::PRINT_ON)
        {
            std::cout << OPER_COPY_PRE_PRINT << name_ << POST_PRINT;
        }
        return *this;
    }

    void setSize(int inNewSize) noexcept
    {
        if (memory_.size() != inNewSize)
        {
            memory_ = ARRAII<T>(inNewSize);
        }
    }

    ~CTable()
    {
        if (flag::PRINT_ON)
        {
            std::cout << DTOR_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    void setVal(int idx, T newVal) noexcept
    {
        if (isProperIdx(idx, getSize()))
        {
            memory_[idx] = newVal;
        }
    }

    T getVal(int idx) const noexcept
    {
        T retVal;
        if (isProperIdx(idx, getSize()))
        {
            retVal = memory_[idx];
        }
        return retVal;
    }

    std::size_t getSize() const noexcept
    {
        return memory_.size();
    }

    std::string getName() const noexcept
    {
        return std::string(name_);
    }

    bool operator==(const CTable& inObj) const noexcept
    {
        return memory_ == inObj.memory_ && name_ == inObj.name_;
    }

    void swap(CTable& first, CTable& second)
    {
        using std::swap;
        ARRAII<T>::swap(first.memory_, second.memory_);
        swap(first.name_, second.name_);
    }

    friend std::ostream& operator<< (std::ostream& stream, const CTable& inVal)
    {
        stream<<static_cast<std::string>(inVal);
        return stream;
    }

    explicit operator std::string() const noexcept
    {
        std::stringstream retVal;
        retVal << POST_PRINT << memory_;

        return std::move(retVal.str());
    }

    T& operator[](int idx) const noexcept
    {
        return memory_[idx];
    }

    static CTable<T>* buildNewObj(size_t size = DEFAULT_IN_TABLE_SIZE) noexcept
    {
        return new CTable<T>(size);
    }

    static CTable<T>* buildNewObj(CTable* inVal) noexcept
    {
        return new CTable<T>(*inVal);
    }

private:
    std::string name_ = DEFAULT_TABLE_NAME;
    ARRAII<T> memory_;
};

template<class T>
using Vec_PtrCTable = std::vector<T*, CTable<T>*>;
