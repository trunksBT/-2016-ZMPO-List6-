#include "stdafx.h"
#include "CTable.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>

using namespace defaultVals;
using namespace flags;

CTable::CTable()
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = DEFAULT_IN_TABLE_SIZE;
    allocateMemory(size_);
    initTable(ZERO);
    if(printFlagOn)
    {
        std::cout << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(int inSize)
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(ZERO);
    if(printFlagOn)
    {
        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    }
}

void CTable::print()
{
    for(int i = 0; i < size_; i++)
    {
        std::cout << memory_[i] << std::endl;
    }
}

CTable::CTable(std::string inVal)
{
    name_ = std::move(inVal);
    size_ = DEFAULT_IN_TABLE_SIZE;
    allocateMemory(size_);
    initTable(ZERO);
    if(printFlagOn)
    {
        std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable::CTable(CTable& inVal)
{
    copyCtor(inVal);
}

void CTable::initTable(int defaultVal)
{
    for(int i = 0; i < size_; i++)
    {
        memory_[i] = defaultVal;
    }
}

void CTable::copyCtor(CTable& inVal)
{
    name_ = inVal.name_;
    size_ = inVal.size_;
    name_.append(POST_COPIED_NAME);
    allocateMemory(size_);
    deepCopy(inVal);
    if(printFlagOn)
    {
        std::cout << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
    }
}

CTable& CTable::operator=(CTable& inObj)
{
    copyCtor(inObj);
    return *this;
}

CTable* CTable::buildNewObj()
{
    return new CTable();
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
    if(printFlagOn)
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
    if(idx > -1 && idx < size_)
    {
        memory_[idx] = newVal;
    }
}

int CTable::getVal(int idx) const
{
    int retVal = std::numeric_limits<int>::min();
    if(idx > -1 && idx < size_)
    {
        retVal = memory_[idx];
    }
    return retVal;
}

int CTable::getSize() const
{
    return size_;
}

std::string& CTable::getName()
{
    return name_;
}
