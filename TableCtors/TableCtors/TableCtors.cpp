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
        Flyweight application;
        Flyweight::interpretCommand(stub::setName0);
        Flyweight::interpretCommand(stub::createDefs10);
        Flyweight::interpretCommand(stub::createDefs10);
        Flyweight::interpretCommand(stub::createDef6);
        Flyweight::interpretCommand(stub::setName0);
        Flyweight::interpretCommand(stub::getName0);
        Flyweight::interpretCommand(stub::getSize0);
        Flyweight::interpretCommand(stub::removeAll);
   }

   std::cout << std::endl;
   //return RUN_ALL_TESTS();
   return 0;
}


