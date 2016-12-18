// Copyrights TrunkBT_KorytkoBT
#include <gtest/gtest.h>

#include <Utils/Interface.hpp>
#include <ElementsAndTables/CTable.hpp>

//#include <Utils/Stub.hpp>
//#include <Utils/Utils.hpp>
//#include <Utils/UtilsForMT.h>
//#include <Flyweight/Flyweight.h>
//#include <Utils/UtilsForMT.h>

//using namespace defaultVals;
//using namespace assertWrapper;
//using namespace funs;

int main(int argc, char **argv)
{
    {
    //     CFlyweight application;
         ERROR_CODE commandResult = ERROR_CODE::INITIAL_VAL;

         logger << "Pass command" << POST_PRINT;
         do
         {
             auto command = receiveAndLexCommandFromUser();
             for (int i = 0; i < command.size(); i++)
             {
                 logger << command[i] << POST_PRINT;
             }
             //commandResult = application.interpretCommand(command);
         } while(commandResult != ERROR_CODE::CLOSE);

         logger << POST_PRINT << "Dzieki za uzycie programu, Korytko_MS" << POST_PRINT << POST_PRINT;
         system("Pause");
    }
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}

