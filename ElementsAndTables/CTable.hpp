#pragma once

#include <string>
#include <vector>
#include <Utils/Utils.hpp>
#include <ElementsAndTables/RAII.hpp>

using namespace defaultVals;

template<typename T>
class CTable
{
public:
    CTable(size_t size = DEFAULT_IN_TABLE_SIZE)
        : memory_(RAII<T>(size))
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
        return *this;
        if (flag::PRINT_ON)
        {
            std::cout << OPER_COPY_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    void setSize(int inNewSize) noexcept
    {
        if (memory_.size() != inNewSize)
        {
            memory_ = RAII<T>(inNewSize);
        }
    }

    ~CTable()
    {
        if (flag::PRINT_ON)
        {
            std::cout << DTOR_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    void setVal(int idx, int newVal)
    {
        if (isProperIdx(idx, size_))
        {
            memory_[idx] = newVal;
        }
    }

    int getVal(int idx) const
    {
        int retVal = std::numeric_limits<int>::min();
        if (isProperIdx(idx, size_))
        {
            retVal = memory_[idx];
        }
        return retVal;
    }

    std::size_t getSize() const noexcept
    {
        return memory_.size();
    }

    std::string getName() const
    {
        return std::string(name_);
    }

    std::string toString() const
    {
        std::stringstream retVal;
        retVal << BRACKET_OPEN << name_;
        retVal << SPACE << LEN << SEPARATOR << size_;
        retVal << SPACE << VALUES << SEPARATOR;

        for (int i = 0; i < size_; i++)
        {
            retVal << memory_[i] << COMMA_SPACE;
        }

        std::string stringedStream(retVal.str());
        stringedStream = stringedStream.substr(ZERO, stringedStream.size() - TWO);

        return std::move(stringedStream + std::string(BRACKET_CLOSE));
    }

    static CTable<T>* buildNewObj(size_t size = DEFAULT_IN_TABLE_SIZE)
    {
        return new CTable<T>(size);
    }

private:
    std::string name_ = DEFAULT_TABLE_NAME;
    RAII<T> memory_;
};

template<class T>
using Vec_PtrCTable = std::vector<T*, CTable<T>*>;
