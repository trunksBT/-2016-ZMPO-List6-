// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <boost/optional.hpp>
#include <boost/tokenizer.hpp>
#include "Interface.h"

using namespace boost;

int main()
{
    constexpr char* SEPARATOR = " ";
    std::string str = "fun1 fun2 2323 ";
    using tokenizer = boost::tokenizer<boost::char_separator<char> >;
    boost::char_separator<char> sep(SEPARATOR);
    tokenizer tokens(str, sep);
    std::vector<std::string> retVal(tokens.begin(), tokens.end());

    return 0;
}
