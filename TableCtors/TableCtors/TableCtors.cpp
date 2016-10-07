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
      //RAIIFlyweightCTable application(stub::createDef);
      // ***************** DEAFAULT CACHE *****************
      // ***************** OWN CACHE *****************
      RAIIFlyweightCTable application(stub::createDefs6);

      RAIIFlyweightCTable::receiveCommand(stub::getSize0);
      RAIIFlyweightCTable::receiveCommand(stub::getSize10);    

      RAIIFlyweightCTable::receiveCommand(stub::remove0);
      RAIIFlyweightCTable::receiveCommand(stub::remove10);

      RAIIFlyweightCTable::receiveCommand(stub::getName0);
      RAIIFlyweightCTable::receiveCommand(stub::getName10);

      RAIIFlyweightCTable::receiveCommand(stub::removeAll);
#else
      RAIIFlyweightCTable application(communication::receiveCommandFromUser());
#endif
   }
   ~MainRunner()
   {
      Flyweight::releaseResources();
   }
private:
   //std::vector<CTable*> inCache =
   //{
   //   nullptr,
   //   nullptr,
   //   new CTable(),
   //   new CTable(),
   //   nullptr
   //};
};

int main(int argc, char **argv)
{
   //::testing::InitGoogleTest(&argc, argv);

   {
      MainRunner mainApp;
   }

   std::cout << std::endl;
   //return RUN_ALL_TESTS();
   return 0;
}


