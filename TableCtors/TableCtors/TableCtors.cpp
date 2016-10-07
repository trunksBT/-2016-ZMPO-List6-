// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#include <boost/optional.hpp>
#include <boost/tokenizer.hpp>

#include "Stub.hpp"
#include "Utils.hpp"
#include "CTable.hpp"
#include "Interface.hpp"
#include "TableCtors.h"
#include "Flyweight.h"
#include "RAIIFlyweightCTable.h"

using namespace defaultVals;
using namespace communication;

#define STUB

class MainRunner
{
public:
   MainRunner()
   {
#ifdef STUB
      RAIIFlyweightCTable application(stub::createDef);
      // ***************** DEAFAULT CACHE *****************
      //RAIIFlyweightCTable application(stub::createDefs);
      // ***************** OWN CACHE *****************
      //RAIIFlyweightCTable application(stub::createDefs20);
      RAIIFlyweightCTable::receiveCommand(stub::getName0);
      //RAIIFlyweightCTable::receiveCommand(stub::getName11);

#else
      RAIIFlyweightCTable application(communication::receiveCommandFromUser());
#endif
   }
   ~MainRunner()
   {
      Flyweight::releaseResources(inCache);
   }
private:
   std::vector<CTable*> inCache =
   {
      nullptr,
      nullptr,
      new CTable(),
      new CTable(),
      nullptr
   };
};

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);

   {
      MainRunner mainApp;
   }

   std::cout << std::endl;
   return RUN_ALL_TESTS();
}


