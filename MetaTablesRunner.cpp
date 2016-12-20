// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>

#include <Utils/Interface.hpp>
#include <Flyweight/Flyweight.hpp>
#include <ElementsAndTables/CTable.hpp>

//#include <Utils/Stub.hpp>
//#include <Utils/Utils.hpp>
//#include <Utils/UtilsForMT.h>
//#include <Utils/UtilsForMT.h>

//using namespace defaultVals;
//using namespace assertWrapper;
//using namespace funs;

int main(int argc, char **argv)
{
    //{
    //     CFlyweight application;
    //     CODE commandResult = CODE::INITIAL_VAL;

    //     logger << "Pass command" << POST_PRINT;
    //     do
    //     {
    //         auto command = receiveAndLexCommandFromUser();
    //         commandResult = application.interpretCommand(command);
    //     } while(commandResult != CODE::CLOSE);

    //     logger << POST_PRINT << "Dzieki za uzycie programu, Korytko_MS" << POST_PRINT << POST_PRINT;
    //}

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

