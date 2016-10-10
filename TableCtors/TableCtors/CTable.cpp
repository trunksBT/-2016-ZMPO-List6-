#include "stdafx.h"
#include "CTable.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>

using namespace defaultVals;
using namespace funs;

CTable::CTable()
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = DEFAULT_IN_TABLE_SIZE;
    allocateMemory(size_);
    initTable(memory_, size_, ZERO);
    if(flag::printOn)
    {
        std::cout << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(int inSize)
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, ZERO);
    if(flag::printOn)
    {
        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(int inSize, int initValue)
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, initValue);
    if(flag::printOn)
    {
        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(std::string inName)
{
    name_ = inName;
    size_ = DEFAULT_IN_TABLE_SIZE;
    allocateMemory(size_);
    initTable(memory_, size_, ZERO);
    if(flag::printOn)
    {
        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(int inSize, std::string inName)
{
    name_ = inName;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, ZERO);
    if(flag::printOn)
    {
        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(CTable& inVal)
{
    copyCtor(inVal);
}

void CTable::initTable(int* table, int size, int defaultVal)
{
    for(int i = 0; i < size; i++)
    {
        table[i] = int(defaultVal);
    }
}

void CTable::copyCtor(CTable& inVal)
{
    name_ = inVal.name_;
    size_ = inVal.size_;
    name_.append(POST_COPIED_NAME);
    allocateMemory(size_);
    deepCopy(inVal);
    if(flag::printOn)
    {
        std::cout << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable& CTable::operator=(CTable& inObj)
{
    copyCtor(inObj);
    return *this;
}

void CTable::changeSize(int inNewSize)
{
    if(size_ != inNewSize)
    {
        int* newTable = new int[inNewSize];
        if(size_ < inNewSize)
        {
            initTable(newTable, inNewSize, ZERO);
        }
        for(int i = 0; i < size_ && i < inNewSize; i++)
        {
            newTable[i] = int(memory_[i]);
        }
        delete[] memory_;
        memory_ = newTable;
        size_ = inNewSize;
    }
}

CTable* CTable::buildNewObj()
{
    return new CTable();
}

CTable* CTable::buildNewObj(CTable& inVal)
{
    return new CTable(inVal);
}

CTable* CTable::buildNewObj(int inSize)
{
    return new CTable(inSize);
}

CTable* CTable::buildNewObj(int inSize, int inInitValue)
{
    return new CTable(inSize, inInitValue);
}

CTable* CTable::buildNewObj(int inSize, std::string inName)
{
    return new CTable(inSize, inName);
}

void CTable::allocateMemory(int size)
{
    memory_ = new int[size];
}

void CTable::deepCopy(CTable& inVal)
{
    for(int i = 0; i < inVal.size_; i++)
    {
        memory_[i] = int(inVal.memory_[i]);
    }
}

CTable::~CTable()
{
    deallocateMemory();
    if(flag::printOn)
    {
        std::cout << DTOR_PRE_PRINT << name_ << POST_PRINT;
    }
}

void CTable::setName(std::string inName)
{
    name_ = std::move(inName);
}

void CTable::deallocateMemory()
{
    delete[] memory_;
}

void CTable::setVal(int idx, int newVal)
{
    if(isProperIdx(idx, size_))
    {
        memory_[idx] = newVal;
    }
}


int CTable::getVal(int idx) const
{
    int retVal = std::numeric_limits<int>::min();
    if(isProperIdx(idx, size_))
    {
        retVal = memory_[idx];
    }
    return retVal;
}

int CTable::getSize() const
{
    return size_;
}

std::string CTable::getName() const
{
    return std::string(name_);
}

std::string CTable::toString()
{
    std::stringstream retVal;
    retVal << BRACKET_OPEN << name_;
    retVal << SPACE << LEN << SEPARATOR << size_;
    retVal << SPACE << VALUES << SEPARATOR;

    for(int i = 0; i < size_; i++)
    {
        retVal << memory_[i] << COMMA_SPACE;
    }

    std::string stringedStream(retVal.str());
    stringedStream = stringedStream.substr(ZERO, stringedStream.size() - TWO);

    return std::move(stringedStream + std::string(BRACKET_CLOSE));
}

