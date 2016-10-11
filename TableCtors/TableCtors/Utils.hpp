#pragma once

#include <vector>
#include "CTable.hpp"
#include <limits>

namespace flag
{
constexpr bool printOn = true;
constexpr bool debugTestsOn = false;
}

enum class ERROR_CODE : int
{
    SEEMS_LEGIT = 0, // when all is good(probably)
    UNDEFINED_OBJECT = 1, // when isProperIdx(idx) == true, situation when vector has allocated memory
    INDEX_OUT_OF_BOUNDS = 2, // when isProperIdx(idx) == false
    ERROR_COMMAND_PARSING = 3, // it will be used when parsing has errors or undefined command
    NOT_HANDLED_ERROR_REPORTING = 4,
    INITIAL_VAL = 5,
    WRONG_AMOUNT_OF_ARGS = 6,
    ERROR_ARGS_PARSING = 7, // when args amount is proper, but type is wrong
    WRONG_VALUE = 8, // when new size must be minus
    CLOSE = 10 // when new size must be minus
};

namespace defaultVals
{
constexpr const char* BASH_DOLAR = "$ ";
constexpr const char* PRE_PRINT = "   ";
constexpr const char* POST_PRINT = "\n";
constexpr const char* SEPARATOR = ": ";
constexpr const char* BRACKET_OPEN = "( ";
constexpr const char* BRACKET_CLOSE = " )";
constexpr const char* LEN = "len";
constexpr const char* VALUES = "values";
constexpr const char* SPACE = " ";
constexpr const char* COMMA_SPACE = ", ";
constexpr const char* DEFAULT_TABLE_NAME = "KORYTKO_TABLE";
constexpr const char* POST_COPIED_NAME = "_copy";
constexpr const char* DTOR_PRE_PRINT = "usuwam: ";
constexpr const char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
constexpr const char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
constexpr const char* CTOR_DEFAULT_MOVE_PRINT = "przenoszenie: ";
constexpr const char* CTOR_ARG1_PRE_PRINT = "parametr: ";
constexpr const int INITIAL_FLYWEIGHT_CACHE_SIZE = 5;
constexpr const int ZERO = 0;
constexpr const int MINUS_ONE = -1;
constexpr const int ONE = 1;
constexpr const int TWO = 2;
constexpr const int FIVE = 5;
constexpr const int TEN = 10;
constexpr const long MAX_INT_VAL = (std::numeric_limits<int>::max)();
constexpr const int DEFAULT_IN_TABLE_SIZE = TWO;
constexpr const char* ERRORED_COMMAND_IDX = "Errored command idx";
constexpr const char INT_TYPE = 'i';
constexpr const char STRING_TYPE = 's';
}

namespace funs
{
bool isProperIdx(int idxOrAmount, std::vector<CTable*>& inCache);
bool isProperIdx(int idx, int size);
std::string toString(ERROR_CODE inCode);
bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs);
bool isNumber(std::string inChain);
bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs);
bool isVectorEmpty(std::vector<CTable*>& inCache);
int toInt(char inChar);
}

namespace idxOf
{
constexpr int COMMAND = 0;
constexpr int ID_OF_CTABLE = 1;
constexpr int AMOUNT = 1;
constexpr int NEW_NAME = 2;
constexpr int NEW_SIZE = 2;
constexpr int GOAL_ID = 2;
constexpr int NEW_VAL = 3;
constexpr int INITIAL_NAME = 3;
}

namespace messageLiterals
{
constexpr const char* CREATE = "create"; // <nrTablicy> <rozmiar> <nazwaTablicy> - wywo³uje parametryczny kontruktor
constexpr const char* CREATE_DEF = "createDef"; // calls default ctor for obj with number 
constexpr const char* CREATE_DEFS = "createDefs"; // calls default ctor for number of obj
constexpr const char* CREATE_COPY = "createCopy"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
constexpr const char* GET_NAME = "getName"; // getName of CTable on idx
constexpr const char* GET_SIZE = "getSize"; // getSize of CTable on idx
constexpr const char* GET_VALUE = "getValue"; // getValue from table in CTable <nrTablicy> <nrPozycji>
constexpr const char* REMOVE = "remove"; // remove CTable on idx
constexpr const char* REMOVE_ALL = "removeAll"; // remove CTable on idx
constexpr const char* SET_NAME = "setName"; // set name of CTable on idx
constexpr const char* SET_VALUE = "setValue"; // set value of CTable <nrTablicy> on <nrPozycji> onto <wartoœæ>
constexpr const char* PRINT = "print"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
constexpr const char* PRINT_ALL = "printAll"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
constexpr const char* CHANGE_SIZE = "changeSize"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
constexpr const char* CLOSE = "close"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
constexpr const char* HELP = "help"; // <nrTablicy> <rozmiar> <nazwaTablicy> - wywo³uje parametryczny kontruktor
}

namespace commandArgs
{
constexpr const char* IDX = "<idx>";
constexpr const char* SIZE = "<size>";
constexpr const char* NAME = "<name>";
constexpr const char* VALUE = "<value>";

}

namespace fullCommands
{
extern std::string createArgs;
extern std::string createDefArgs;
extern std::string createDefsArgs;
extern std::string createCopyArgs;
extern std::string getNameArgs;
extern std::string getSizeArgs;
extern std::string getValueArgs;
extern std::string setValueArgs;
extern std::string setNameArgs;
extern std::string printArgs;
extern std::string printAllArgs;
extern std::string removeArgs;
extern std::string removeAllArgs;
extern std::string changeSizeArgs;
extern std::string closeArgs;
extern std::string helpArgs;
extern std::vector<std::string> allCommands;
}



