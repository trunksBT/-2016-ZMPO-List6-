// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#include "Stub.hpp"
#include "Utils.hpp"
#include "CTable.hpp"
#include "Interface.hpp"
#include "Flyweight.h"

using namespace defaultVals;
using namespace communication;

#define STUB

int main(int argc, char **argv)
{
   //::testing::InitGoogleTest(&argc, argv);

   {
        Flyweight application(stub::createDefs6);
        Flyweight::receiveCommand(stub::setName0);
        Flyweight::receiveCommand(stub::getName0);
   }

   std::cout << std::endl;
   //return RUN_ALL_TESTS();
   return 0;
}


