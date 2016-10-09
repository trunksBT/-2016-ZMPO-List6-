#include "stdafx.h"
#include <iostream>

#include "SetValueHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

SetValueHandler::SetValueHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

ERROR_CODE SetValueHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }

    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedIdOfNewVal(wholeCommand_[idxOf::goalId]);
    int idOfNewVal = std::stoi(receivedIdOfNewVal);
    std::string receivedNewVal(wholeCommand_[idxOf::newVal]);
    int newVal = std::stoi(receivedNewVal);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            if(isProperIdx(idOfNewVal, retTable->getSize()))
            {
                retTable->setVal(idOfNewVal,newVal);
            }
            else
            {
                resultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
                if(flag::printOn)
                {
                    std::cout << toString(resultCode);
                }
            }
        }
        else
        {
            resultCode = ERROR_CODE::UNDEFINED_OBJECT;
            if(flag::printOn)
            {
                std::cout << toString(resultCode);
            }
        }
        retTable = nullptr;
    }
    else
    {
        resultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::printOn)
        {
            std::cout << toString(resultCode);
        }
    }
    return resultCode;
}

SetValueHandler::~SetValueHandler()
{}

