// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

#include "Stub.hpp"
#include "Utils.hpp"
#include "Interface.hpp"
#include "Flyweight.h"
#include "UtilsForMT.h"

using namespace defaultVals;
using namespace communication;
using namespace assertWrapper;

#define STUB

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);

   {
        //Flyweight application;
        //std::vector<ERROR_CODE> stackTrace;
        //ERROR_CODE commandResult = ERROR_CODE::INITIAL_VAL;

        //std::cout << "Pass command" << std::endl;
        //do
        //{
        //    auto command = receiveAndLexCommandFromUser();
        //    commandResult = application.interpretCommand(command);
        //    stackTrace.emplace_back(commandResult);
        //} while(stackTrace.back() != ERROR_CODE::CLOSE);

        //ResultCode resultCode = getFinalResultCode(stackTrace);
        //CHECK_IF_FINISHED_PROPER(ERROR_CODE::SEEMS_LEGIT, resultCode);
        //std::cout << std::endl << "Dzieki za uzycie programu, MS" << POST_PRINT << POST_PRINT;
   }

   return RUN_ALL_TESTS();
   return 0;
}


