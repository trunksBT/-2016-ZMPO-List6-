#include "stdafx.h"
#include <iostream>

#include "ChangeSizeHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CChangeSizeHandler::CChangeSizeHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE CChangeSizeHandler::performOn(std::vector<CTable*>& inCache)
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

void CChangeSizeHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedSourceId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int sourceId = std::stoi(receivedSourceId);
    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
    int newSize = std::stoi(receivedNewSize);

    if(isProperIdx(sourceId, inCache))
    {
        if(newSize > MINUS_ONE)
        {
            if(inCache[sourceId] == nullptr)
            {
                inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
                if(flag::PRINT_ON)
                {
                    std::cout << toString(inResultCode);
                }
            }
            else
            {
                inCache[sourceId]->changeSize(newSize);
            }
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
    else
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::PRINT_ON)
        {
            std::cout << toString(inResultCode);
        }
    }
}

CChangeSizeHandler::~CChangeSizeHandler()
{}
