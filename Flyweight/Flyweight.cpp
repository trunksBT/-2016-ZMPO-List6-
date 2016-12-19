#include "Flyweight.hpp"

#include <Utils/Logger.hpp>
#include <Handlers/GoHandler.hpp>
#include <Handlers/CreateHandler.hpp>
#include <Handlers/PrintAllHandler.hpp>
#include <Handlers/CreateCopyHandler.h>

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

    InitializedCTable pairedShapeCache= std::forward_as_tuple(
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
    else if (command == PRINT_ALL)
    {
        returnedCode = CPrintAllHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    else if (command == CREATE_COPY)
    {
        returnedCode = CCreateCopyHandler(inCommand).checkArgsAndPerform(pairedShapeCache);
    }
    //else if (command == DELETE)
    //{
    //    CRemoveHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == CLEAR)
    //{
    //    CClearHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == REMOVE_ALL)
    //{
    //    CRemoveAllHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == SET_NAME)
    //{
    //    CSetNameHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == SET_VALUE)
    //{
    //    CSetValueHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == GET_NAME)
    //{
    //    CGetNameHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == GET_SIZE)
    //{
    //    CGetSizeHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == GET_VALUE)
    //{
    //    CGetValueHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == PRINT)
    //{
    //    CPrintHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == PRINT_ALL)
    //{
    //    CPrintAllHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == SET_SIZE)
    //{
    //    CChangeSizeHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    //else if (command == HELP)
    //{
    //    CHelpHandler evaluate(inCommand);
    //    returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    //}
    else if (command == CLOSE)
    {
        releaseResources();
        returnedCode = CODE::CLOSE;
    }

    return returnedCode;
}

void CFlyweight::releaseResources()
{
    delete shapeCache_;
    shapeCache_ = nullptr;
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}
