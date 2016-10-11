#include "stdafx.h"
#include "Utils.hpp"
#include "CTable.hpp"
#include <map>
#include <iostream>
#include <string>

using namespace defaultVals;

namespace funs
{
    bool isProperIdx(int idxOrAmount, std::vector<CTable*>& inCache)
    {
        return idxOrAmount > MINUS_ONE && idxOrAmount < inCache.size();
    }

    bool isProperIdx(int inIdx, int inSize)
    {
        return inIdx > MINUS_ONE && inIdx < inSize;
    }

    std::string toString(ERROR_CODE inCode)
    {
        static std::map<ERROR_CODE, std::string> codeToString;

        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::SEEMS_LEGIT),
            std::forward_as_tuple("SEEMS_LEGIT"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::UNDEFINED_OBJECT),
            std::forward_as_tuple("UNDEFINED_OBJECT"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::INDEX_OUT_OF_BOUNDS),
            std::forward_as_tuple("INDEX_OUT_OF_BOUND"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::ERROR_COMMAND_PARSING),
            std::forward_as_tuple("ERROR_COMMAND_PARSING"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::NOT_HANDLED_ERROR_REPORTING),
            std::forward_as_tuple("NOT_HANDLED_ERROR_REPORTING"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::INITIAL_VAL),
            std::forward_as_tuple("INITIAL_VAL"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::WRONG_AMOUNT_OF_ARGS),
            std::forward_as_tuple("WRONG_AMOUNT_OF_ARGS"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::ERROR_ARGS_PARSING),
            std::forward_as_tuple("ERROR_ARGS_PARSING"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::WRONG_VALUE),
            std::forward_as_tuple("WRONG_VALUE"));
        codeToString.emplace(std::piecewise_construct,
            std::forward_as_tuple(ERROR_CODE::CLOSE),
            std::forward_as_tuple("WRONG_VALUE"));

        return codeToString[inCode];
    }

    bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs)
    {
        return inCommand.size() >= inProperAmountOfArgs;
    }

    bool isIntLimit(std::string inChain)
    {
        bool isLimit = true;

        if(inChain.size() > 5)
        {
            return true;
        }
        else if(inChain.size() < 5)
        {
            return false;
        }

        long inLong = std::stol(inChain);

        if(inLong <= MAX_INT_VAL)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool isNumber(std::string inChain)
    {
        bool isNumber = true;

        if(isIntLimit(inChain))
        {
            return false;
        }
        else if(inChain.size() == ONE && inChain[ZERO] == '-')
        {
            return false;
        }

        for(int i = 0; i < inChain.size() && isNumber; i++)
        {
            if(i == 0 && inChain[i] == '-')
            {
                isNumber &= true;
            }
            else if(isdigit(inChain[i]))
            {
                isNumber &= true;
            }
            else
            {
                isNumber &= false;
            }
        }

        return isNumber;
    }

    ERROR_CODE returnResultCode(ERROR_CODE inResultCode)
    {
        ERROR_CODE resultCode = inResultCode;
        if(flag::PRINT_ON)
        {
            std::cout << toString(resultCode);
        }
        return resultCode;
    }

    bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs)
    {
        bool isProperType = true;
        for(int i = 0; i < inCommand.size() && isProperType && i< inProperTypeOfArgs.size(); i++)
        {
            if(inProperTypeOfArgs[i] == INT_TYPE && !isNumber(inCommand[i]))
            {
                isProperType &= false;
            }
        }
        return isProperType;
    }

    bool isVectorEmpty(std::vector<CTable*>& inCache)
    {
        bool isEmpty = true;
        for(int i = 0; i < inCache.size(); i++)
        {
            isEmpty = inCache[i] == nullptr;
        }
        return isEmpty;
    }

    int toInt(char inChar)
    {
        return inChar - 48;
    }

}
namespace fullCommands
{
    std::string createArgs =
        std::string(messageLiterals::CREATE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::SIZE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::NAME);

    std::string createDefArgs =
        std::string(messageLiterals::CREATE_DEF) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string createDefsArgs =
        std::string(messageLiterals::CREATE_DEFS) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::SIZE);

    std::string createCopyArgs =
        std::string(messageLiterals::CREATE_COPY) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string getNameArgs =
        std::string(messageLiterals::GET_NAME) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string getSizeArgs =
        std::string(messageLiterals::GET_SIZE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string getValueArgs =
        std::string(messageLiterals::GET_VALUE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string setValueArgs =
        std::string(messageLiterals::SET_VALUE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::VALUE);

    std::string setNameArgs =
        std::string(messageLiterals::SET_NAME) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::NAME);

    std::string printArgs =
        std::string(messageLiterals::PRINT) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string printAllArgs =
        std::string(messageLiterals::PRINT_ALL);

    std::string deleteArgs =
        std::string(messageLiterals::DELETE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string deleteAllArgs =
        std::string(messageLiterals::REMOVE_ALL);

    std::string setSizeArgs =
        std::string(messageLiterals::SET_SIZE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::SIZE);

    std::string clearArgs =
        std::string(messageLiterals::CLEAR) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string closeArgs =
        std::string(messageLiterals::CLOSE);

    std::string helpArgs =
        std::string(messageLiterals::HELP);

    std::vector<std::string> allCommands =
    {
        createArgs,
        createDefArgs,
        createDefsArgs,
        createCopyArgs,
        getNameArgs,
        getSizeArgs,
        getValueArgs,
        setValueArgs,
        setNameArgs,
        printArgs,
        printAllArgs,
        deleteArgs,
        deleteAllArgs,
        setSizeArgs,
        closeArgs,
        helpArgs
    };
}

