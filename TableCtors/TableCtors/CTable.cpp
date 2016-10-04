#include "stdafx.h"
#include "CTable.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace defaultVals;

CTable::CTable()
{
    name_ = TABLE_NAME;
    std::cout << CTOR_DEFAULT_PRE_PRINT << name_;
}

CTable::CTable(std::string inName)
{
    name_ = std::move(inName);
    std::cout << CTOR_ARG1_PRE_PRINT << name_;
}

CTable::CTable(CTable& inTable)
{
    name_ = (inTable.name_);
    name_.append(POST_COPIED_NAME);
    std::cout << CTOR_COPY_PRE_PRINT << name_;
}

CTable::~CTable()
{}
