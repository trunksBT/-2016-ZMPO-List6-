// TableCtors.cpp : Defines the entry point for the console application.
//

// Copyrights TrunkBT_KorytkoBT
#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>
#include <ElementsAndTables/CTable.hpp>
//#include <ElementsAndTables/RAII.hpp>

//#include <Utils/Stub.hpp>
//#include <Utils/Utils.hpp>
//#include <Utils/UtilsForMT.h>
//#include <Utils/Interface.hpp>
//#include <Flyweight/Flyweight.h>
//#include <Utils/UtilsForMT.h>

//using namespace defaultVals;
//using namespace communication;
//using namespace assertWrapper;
//using namespace funs;

int main(int argc, char **argv)
{
    //{
    //     CFlyweight application;
    //     ERROR_CODE commandResult = ERROR_CODE::INITIAL_VAL;

    //     std::cout << "Pass command" << std::endl;
    //     do
    //     {
    //         auto command = receiveAndLexCommandFromUser();
    //         commandResult = application.interpretCommand(command);
    //     } while(commandResult != ERROR_CODE::CLOSE);

    //     std::cout << std::endl << "Dzieki za uzycie programu, Korytko_MS" << POST_PRINT << POST_PRINT;
    //     system("Pause");
    //}
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

