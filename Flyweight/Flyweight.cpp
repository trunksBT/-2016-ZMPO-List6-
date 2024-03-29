#include "Flyweight.hpp"

#include <Utils/Logger.hpp>
#include <Handlers/GoHandler.hpp>
#include <Handlers/PrintHandler.h>
#include <Handlers/CreateHandler.hpp>
#include <Handlers/PrintAllHandler.hpp>
#include <Handlers/RemoveHandler.h>
#include <Handlers/CreateCopyHandler.h>
#include <Handlers/ChangeSizeHandler.h>
#include <Handlers/GetNameHandler.h>
#include <Handlers/SetNameHandler.h>
#include <Handlers/GetSizeHandler.h>
#include <Handlers/SetValueHandler.h>
#include <Handlers/GetValueHandler.h>
#include <Handlers/ClearHandler.h>

//#include <Utils/UtilsForMT.hpp>
//
//#include <Handlers/CreateRectDoubleHandler.hpp>
//#include <Handlers/CreateSquareDoubleHandler.hpp>
//#include <Handlers/CreateCircleDoubleHandler.hpp>
//#include <Handlers/CreateTriangleDoubleHandler.hpp>
//#include <Handlers/CreateTrapezoidDoubleHandler.hpp>
//
//#include <Handlers/AreaHandler.hpp>
//#include <Handlers/AreasHandler.hpp>
//#include <Handlers/PerimeterHandler.hpp>
//#include <Handlers/PerimetersHandler.hpp>

using namespace defaultVals;
using namespace messageLiterals;
using namespace funs;

CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    CODE returnedCode = CODE::WRONG_VALUE;

    if (inCommand.size() == ZERO)
    {
        return CODE::WRONG_VALUE;
    }

    std::string command(inCommand[idxOf::COMMAND]);

    InitializedCTable pairedShapeCache = std::forward_as_tuple(
        shapeCache_,
        shapeCacheIsInitialized_);

    if (command == GO)
    {
        returnedCode = CGoHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
        shapeCache_ = std::get<0>(pairedShapeCache);
    }
    if (command == CREATE)
    {
        returnedCode = CCreateHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == PRINT)
    {
        returnedCode = CPrintHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == PRINT_ALL)
    {
        returnedCode = CPrintAllHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == CREATE_COPY)
    {
        returnedCode = CCreateCopyHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == REMOVE_ALL)
    {
        releaseResources();
        returnedCode = CODE::SEEMS_LEGIT;
    }
    else if (command == REMOVE)
    {
        returnedCode = CRemoveHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == SET_SIZE)
    {
        returnedCode = CChangeSizeHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == SET_NAME)
    {
        returnedCode = CSetNameHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == GET_NAME)
    {
        returnedCode = CGetNameHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == GET_SIZE)
    {
        returnedCode = CGetSizeHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == SET_VALUE)
    {
        returnedCode = CSetValueHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == GET_VALUE)
    {
        returnedCode = CGetValueHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == CLEAR)
    {
        returnedCode = CClearHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == CLOSE)
    {
        releaseResources();
        returnedCode = CODE::CLOSE;
    }
    //else if (command == HELP)
    //{
    //    CHelpHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}

    return returnedCode;
}

void CFlyweight::releaseResources()
{
    delete shapeCache_;
    shapeCache_ = nullptr;
    shapeCacheIsInitialized_.clear();
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}
