#pragma once

#include <map>
#include <tuple>
#include <string>
#include <sstream>
#include <Utils/Utils.hpp>
#include <ElementsAndTables/ARRAII.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Exceptions.hpp>

using namespace defaultVals;
using namespace funs;
using namespace flags;

template<typename T>
class CTable
{
public:
    CTable(int size)
    {
        memory_ = ARRAII<T>(size);

        if (PRINT_ERRORS)
        {
            logger << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    CTable(int size, std::string inName)
        : memory_(ARRAII<T>(size))
        , name_(inName)
    {
        if (PRINT_ERRORS)
        {
            logger << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    CTable(const CTable& inVal)
        : name_(inVal.name_)
        , memory_(inVal.memory_)
    {
        if (PRINT_ERRORS)
        {
            logger << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    CTable<T>& operator=(const CTable& inObj) 
    {
        CTable<T> temp = inObj;
        swap(*this, temp);
        if (PRINT_ERRORS)
        {
            logger << OPER_COPY_PRE_PRINT << name_ << POST_PRINT;
        }
        return *this;
    }

    void setSize(int inNewSize)
    {
        if (inNewSize >= 0)
        {
            if (memory_.size() != inNewSize)
            {
                memory_ = ARRAII<T>(inNewSize);
            }
        }
        else
        {
            throw InitialSizeLowerOrEqZero();
        }
    }

    ~CTable()
    {
        if (PRINT_ERRORS)
        {
            logger << DTOR_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    void setVal(int idx, T newVal)
    {
        if (isProperIdx(idx, getSize()))
        {
            memory_[idx] = newVal;
        }
        else
        {
            throw IndexOutOfBoundsException();
        }
    }

    T& getVal(int idx)
    {
        if (isProperIdx(idx, getSize()))
        {
            return memory_[idx];
        }
        else
        {
            throw IndexOutOfBoundsException();
        }
    }

    int getSize() const noexcept
    {
        return memory_.size();
    }

    std::string getName() const noexcept
    {
        return std::string(name_);
    }

    void setName(std::string inNewName) noexcept
    {
        name_ = inNewName;
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

    static CTable<T>* buildNewObj(int size)
    {
        if (size <= ZERO)
        {
            throw InitialSizeLowerOrEqZero();
        }
        return new CTable<T>(size);
    }

    static CTable<T>* buildNewObj(int size, std::string name)
    {
        if (size <= ZERO)
        {
            throw InitialSizeLowerOrEqZero();
        }
        return new CTable<T>(size, name);
    }

    static CTable<T> buildNewObjRef(int size, std::string name)
    {
        if (size <= ZERO)
        {
            throw InitialSizeLowerOrEqZero();
        }
        return CTable<T>(size, name);
    }

    static CTable<T>* buildNewObj(CTable* inVal) noexcept
    {
        return new CTable<T>(*inVal);
    }

    static CTable<T> buildNewObjRef(CTable& inVal) noexcept
    {
        return CTable<T>(inVal);
    }

private:
    std::string name_ = DEFAULT_TABLE_NAME;
    ARRAII<T> memory_;
};
using TableOfTables = CTable<CTable<int>>;
using InitializedCTable = 
    std::tuple< TableOfTables*, std::map<int, bool>& >;
