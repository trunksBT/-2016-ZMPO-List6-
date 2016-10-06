#include "stdafx.h"
#include "CTable.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace defaultVals;

CTable::CTable()
{
   size_ = DEFAULT_IN_TABLE_SIZE;
   inTable_ = new int[size_];
   name_ = TABLE_NAME;
   std::cout << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
}

CTable::CTable(std::string inVal)
{
   name_ = std::move(inVal);
   std::cout << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CTable::CTable(CTable& inVal)
{
   name_ = (inVal.name_);
   name_.append(POST_COPIED_NAME);
   std::cout << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
}

CTable::~CTable()
{
   std::cout << DTOR_PRE_PRINT << name_ << POST_PRINT;
}

void CTable::setName(std::string inVal)
{
   name_ = std::move(inVal);
}

int CTable::getSize() const
{
   return size_;
}
