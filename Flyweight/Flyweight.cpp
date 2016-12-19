#include "Flyweight.hpp"

#include <Utils/Logger.hpp>
#include <Handlers/IHandler.h>

//#include <Utils/UtilsForMT.hpp>
//
//#include <Handlers/GoHandler.hpp>
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
//#include <Handlers/PrintAllHandler.hpp>

using namespace defaultVals;
using namespace messageLiterals;
using namespace funs;

CTable<CTable<int>>* CFlyweight::shapeCache_;
std::map<int, bool> CFlyweight::shapeCacheIsInitialized_;

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

    IHandler* evaluate = nullptr;

    if (command == GO)
    {
        //evaluate = new CGoHandler(inCommand);
        //returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    }
    //else if (command == CREATE_RECT_DOUBLE)
    //{
    //    evaluate = new CCreateRectDoubleHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CREATE_SQUARE_DOUBLE)
    //{
    //    evaluate = new CCreateSquareDoubleHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CREATE_CIRCLE_DOUBLE)
    //{
    //    evaluate = new CCreateCircleDoubleHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CREATE_TRIANGLE_DOUBLE)
    //{
    //    evaluate = new CCreateTriangleDoubleHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CREATE_TRAPEZOID_DOUBLE)
    //{
    //    evaluate = new CCreateTrapezoidDoubleHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CALCULATE_AREA)
    //{
    //    evaluate = new CAreaHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CALCULATE_AREAS)
    //{
    //    evaluate = new CAreasHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CALCULATE_PERIMETER)
    //{
    //    evaluate = new CPerimeterHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == CALCULATE_PERIMETERS)
    //{
    //    evaluate = new CPerimetersHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    //else if (command == PRINT_ALL)
    //{
    //    evaluate = new CPrintAllHandler(inCommand);
    //    returnedCode = evaluate->checkArgsAndPerform(pairedShapeCache);
    //}
    else if (command == CLOSE)
    {
        releaseResources();
        returnedCode = CODE::CLOSE;
    }
    //delete evaluate;

    return returnedCode;
}

void CFlyweight::releaseResources()
{
    //for (int i = 0; i < shapeCacheSize_; i++)
    //{
    //    if ( shapeCacheIsInitialized_[i] && shapeCache_[i] != nullptr )
    //    {
    //        delete shapeCache_[i];
    //        shapeCache_[i] = nullptr;
    //    }
    //}
    //delete[] shapeCache_;
    //shapeCache_ = nullptr;
    //shapeCacheSize_ = ZERO;
    //shapeCacheIsInitialized_.clear();
}

CFlyweight::CFlyweight()
{
    //initShapeCache(ZERO);
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}
//
//void CFlyweight::updateIsInitializedShapeCache(int idx, bool newVal)
//{
//    shapeCacheIsInitialized_[idx] = newVal;
//}

//void CFlyweight::initShapeCache(int inCacheSize)
//{
//    if (inCacheSize >= ZERO)
//    {
//        shapeCacheSize_ = inCacheSize;
//        shapeCache_ = nullptr;
//        for (int i = 0; i < shapeCacheSize_; i++)
//        {
//            shapeCacheIsInitialized_[i] = false;
//        }
//
//        shapeCache_ = new CShape*[shapeCacheSize_];
//    }
//}
