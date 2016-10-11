#include "stdafx.h"
#include <iostream>

#include "CreateHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CCreateHandler::CCreateHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE CCreateHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS_))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS_))
        {
            performOnProperArgs(inCache, resultCode);
        }
        else
        {
            resultCode = ERROR_CODE::ERROR_ARGS_PARSING;
            if(flag::PRINT_ON)
            {
                std::cout << toString(resultCode);
            }
        }
    }
    else
    {
        resultCode = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
        if(flag::PRINT_ON)
        {
            std::cout << toString(resultCode);
        }
    }

    return resultCode;
}

void CCreateHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
    int newSize = std::stoi(receivedNewSize);
    std::string initialName(wholeCommand_[idxOf::INITIAL_NAME]);

    if(idxOrAmount < 0)
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::PRINT_ON)
        {
            std::cout << toString(inResultCode);
        }
    }
    else
    {
        if(newSize > 0)
        {
            if(idxOrAmount > inCache.size())
            {
                inCache.resize(idxOrAmount + ONE);
            }
            if(inCache[idxOrAmount] != nullptr)
            {
                delete inCache[idxOrAmount];
            }
            inCache[idxOrAmount] = CTable::buildNewObj(newSize, initialName);
        }
        else
        {
            inResultCode = ERROR_CODE::WRONG_VALUE;
            if(flag::PRINT_ON)
            {
                std::cout << toString(inResultCode);
            }
        }
    }
}

CCreateHandler::~CCreateHandler()
{}
