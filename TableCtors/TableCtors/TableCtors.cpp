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
   ::testing::InitGoogleTest(&argc, argv);

   {
        //Flyweight application;
        ////Flyweight::interpretCommand(stub::createDefs6);
        //Flyweight::interpretCommand(stub::printm1);
        //Flyweight::interpretCommand(stub::print0);
        //Flyweight::interpretCommand(stub::print6);
        //Flyweight::interpretCommand(stub::print10);

   }

   return RUN_ALL_TESTS();
   return 0;
}


