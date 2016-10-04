// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <boost/optional.hpp>

void printIfIsInitilized(boost::optional<int>& inOptionalVal)
{
    if (inOptionalVal.is_initialized())
    {
        std::cout << inOptionalVal.get();
    }
    else
    {
        std::cout << "Not initialized value";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "HelloBoost" << std::endl;
    boost::optional<int> optionalVal;
    printIfIsInitilized(optionalVal);
    return 0;
}
