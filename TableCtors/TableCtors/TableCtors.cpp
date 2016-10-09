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
        Flyweight::interpretCommand(stub::createDefs6);
        Flyweight::interpretCommand(stub::getValue0);
        Flyweight::interpretCommand(stub::getValue1);
        Flyweight::interpretCommand(stub::getValue6);
        Flyweight::interpretCommand(stub::getValue10);

        //Flyweight::interpretCommand(stub::createDefs1);
        //Flyweight::interpretCommand(stub::setName0);
        //Flyweight::interpretCommand(stub::createDefs1);
        //Flyweight::interpretCommand(stub::createDefs1);
        //Flyweight::interpretCommand(stub::createDefs1);
        //Flyweight::interpretCommand(stub::setName10);
        //Flyweight::interpretCommand(stub::removeAll);
        //Flyweight::interpretCommand(stub::createDefs10);
        //Flyweight::interpretCommand(stub::createCopy06);
   }

   //return RUN_ALL_TESTS();
   return 0;
}


