#pragma once

#include <vector>
#include "CTable.hpp"
#include <limits>

namespace flag
{
constexpr bool PRINT_ON = true;
constexpr bool DEBUG_TESTS_ON = false;
}

enum class ERROR_CODE : int
{
    SEEMS_LEGIT = 0,
    UNDEFINED_OBJECT = 1,
    INDEX_OUT_OF_BOUNDS = 2,
    ERROR_COMMAND_PARSING = 3,
    NOT_HANDLED_ERROR_REPORTING = 4,
    INITIAL_VAL = 5,
    WRONG_AMOUNT_OF_ARGS = 6,
    ERROR_ARGS_PARSING = 7,
    WRONG_VALUE = 8,
    CLOSE = 10
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
constexpr const int DEFAULT_TABLE_VAL = -1;
constexpr const int DEFAULT_IN_TABLE_SIZE = FIVE;
constexpr const long MAX_INT_VAL = (std::numeric_limits<int>::max)();
constexpr const char* ERRORED_COMMAND_IDX = "Errored command idx";
constexpr const char INT_TYPE = 'i';
constexpr const char STRING_TYPE = 's';
}

namespace funs
{
int toInt(char inChar);
std::string toString(ERROR_CODE inCode);
bool isNumber(std::string inChain);
bool isProperIdx(int inIdx, int inSize);
bool isVectorEmpty(std::vector<CTable*>& inCache);
bool isProperIdx(int idxOrAmount, std::vector<CTable*>& inCache);
bool isProperIdx(int inIdxOrAmount, std::vector<CTable*>& inCache);
bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs);
bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs);
ERROR_CODE returnResultCode(ERROR_CODE inResultCode);
}

namespace idxOf
{
constexpr const int COMMAND = 0;
constexpr const int ID_OF_CTABLE = 1;
constexpr const int AMOUNT = 1;
constexpr const int NEW_NAME = 2;
constexpr const int NEW_SIZE = 2;
constexpr const int GOAL_ID = 2;
constexpr const int NEW_VAL = 3;
constexpr const int INITIAL_NAME = 3;
}

namespace messageLiterals
{
constexpr const char* CLEAR = "clear";
constexpr const char* CREATE = "create";
constexpr const char* CREATE_DEF = "createDef";
constexpr const char* CREATE_DEFS = "createDefs";
constexpr const char* CREATE_COPY = "createCopy";
constexpr const char* GET_NAME = "getName";
constexpr const char* GET_SIZE = "getSize";
constexpr const char* GET_VALUE = "getValue";
constexpr const char* DELETE = "delete";
constexpr const char* REMOVE_ALL = "deleteAll";
constexpr const char* SET_NAME = "setName";
constexpr const char* SET_VALUE = "setValue";
constexpr const char* PRINT = "print";
constexpr const char* PRINT_ALL = "printAll";
constexpr const char* SET_SIZE = "setSize";
constexpr const char* CLOSE = "close";
constexpr const char* HELP = "help";
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
extern std::string deleteArgs;
extern std::string deleteAllArgs;
extern std::string setSizeArgs;
extern std::string closeArgs;
extern std::string helpArgs;
extern std::vector<std::string> allCommands;
}



