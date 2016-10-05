// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <boost/optional.hpp>
#include <boost/tokenizer.hpp>

#include "Stub.hpp"
#include "Utils.hpp"
#include "CTable.hpp"
#include "Interface.hpp"
#include "TableCtors.h"
#include "Flyweight.h"
#include "RAIIFlyweightCTable.h"

#define STUB

using namespace defaultVals;
using namespace communication;

int main()
{
    {
#ifdef STUB
        RAIIFlyweightCTable application(stub::createDef);
#elif
        RAIIFlyweightCTable application(communication::receiveCommandFromUser());
#endif
    }

    std::cout << std::endl;
    return 0;
}


