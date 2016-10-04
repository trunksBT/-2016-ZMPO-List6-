#include "stdafx.h"
#include "CTable.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace defaultVals;

CTable::CTable()
{
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

void CTable::releaseResources(std::vector<CTable*> &tables)
{
     for (auto i = 0; i< tables.size(); i++)
     {
         delete tables[i];
     }
     tables.clear();
}
