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
    CTable()
        : memory_{make_ptr<T>(DEFAULT_IN_TABLE_SIZE)}
    {
        name_ = DEFAULT_TABLE_NAME;
        size_ = DEFAULT_IN_TABLE_SIZE;
        //initTable(memory_, size_, DEFAULT_TABLE_VAL);
        if (flag::PRINT_ON)
        {
            std::cout << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    //CTable(int inSize)
    //    : memory_{ make_ptr<T>(inSize) }
    //{
    //    name_ = DEFAULT_TABLE_NAME;
    //    size_ = inSize;
    //    //initTable(memory_, size_, DEFAULT_TABLE_VAL);
    //    if (flag::PRINT_ON)
    //    {
    //        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    //    }
    //}

    //CTable(int inSize, int initValue)
    //{
    //    name_ = DEFAULT_TABLE_NAME;
    //    size_ = inSize;
    //    memory_ = make_ptr<T>(size_);
    //    initTable(memory_, size_, initValue);
    //    if (flag::PRINT_ON)
    //    {
    //        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    //    }
    //}

    //CTable(std::string inName)
    //    : memory_{ make_ptr<T>(DEFAULT_IN_TABLE_SIZE) }
    //{
    //    name_ = inName;
    //    size_ = DEFAULT_IN_TABLE_SIZE;
    //    memory_ = make_ptr<T>(size_);
    //    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    //    if (flag::PRINT_ON)
    //    {
    //        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    //    }
    //}

    //CTable(int inSize, std::string inName)
    //    : memory_{ make_ptr<T>(DEFAULT_IN_TABLE_SIZE) }
    //{
    //    name_ = inName;
    //    size_ = inSize;
    //    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    //    if (flag::PRINT_ON)
    //    {
    //        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    //    }
    //}

    CTable(CTable& inVal)
    {
        copyCtor(inVal);
    }

    CTable<T>* clone()
    {
        CTable<T>* newObject = new CTable<T>(*this);
        newObject->setName(this->getName());
        return newObject;
    }

    void initTable()
    {
        initTable(memory_, DEFAULT_IN_TABLE_SIZE, DEFAULT_TABLE_VAL);
    }

    void initTable(int* table, int size, int defaultVal)
    {
        for (int i = 0; i < size; i++)
        {
            table[i] = int(defaultVal);
        }
    }

    void copyCtor(CTable& inVal)
    {
        name_ = inVal.name_;
        size_ = inVal.size_;
        name_.append(POST_COPIED_NAME);
        allocateMemory(size_);
        deepCopy(inVal);
        if (flag::PRINT_ON)
        {
            std::cout << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    CTable<T>& operator=(CTable& inObj)
    {
        delete[] memory_;
        copyCtor(inObj);
        return *this;
    }

    void setSize(int inNewSize)
    {
        if (size_ != inNewSize)
        {
            int* newTable = new int[inNewSize];
            if (size_ < inNewSize)
            {
                initTable(newTable, inNewSize, DEFAULT_TABLE_VAL);
            }
            for (int i = 0; i < size_ && i < inNewSize; i++)
            {
                newTable[i] = int(memory_[i]);
            }
            delete[] memory_;
            memory_ = newTable;
            size_ = inNewSize;
        }
    }

    ~CTable()
    {
        if (flag::PRINT_ON)
        {
            std::cout << DTOR_PRE_PRINT << name_ << POST_PRINT;
        }
    }

    void setName(std::string inName)
    {
        name_ = std::move(inName);
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

    int getSize() const
    {
        return size_;
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

    //CTable<T>* buildNewObj(int inSize, int inInitValue)
    //{
    //    return new CTable<T>(inSize, inInitValue);
    //}

    //CTable<T>* buildNewObj(int inSize, std::string inName)
    //{
    //    return new CTable<T>(inSize, inName);
    //}

    //CTable<T>* buildNewObj()
    //{
    //    return new CTable<T>();
    //}

    //CTable<T>* buildNewObj(CTable& inVal)
    //{
    //    return new CTable<T>(inVal);
    //}

    //CTable<T>* buildNewObj(int inSize)
    //{
    //    return new CTable<T>(inSize);
    //}

    void deepCopy(CTable<T>& inVal)
    {
        for (int i = 0; i < inVal.size_; i++)
        {
            memory_[i] = T(inVal.memory_[i]);
        }
    }

private:
    std::string name_;
    RAII<T> memory_;
    int size_;
};

template<class T>
using Vec_PtrCTable = std::vector<T*, CTable<T>*>;
