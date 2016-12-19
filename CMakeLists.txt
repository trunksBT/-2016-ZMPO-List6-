cmake_minimum_required (VERSION 2.6)
 
project (MetaTables)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(googletest/googletest)
include_directories(googletest/googletest/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include_directories(.)

set(HANDLERS
    Handlers/IHandler.cpp
    Handlers/IHandler.h
    Handlers/GoHandler.cpp
    Handlers/GoHandler.hpp
    Handlers/CreateHandler.cpp
    Handlers/CreateHandler.hpp
    Handlers/PrintAllHandler.cpp
    Handlers/PrintAllHandler.hpp
    Handlers/CreateCopyHandler.cpp
    Handlers/CreateCopyHandler.h
    #Handlers/RemoveAllHandler.cpp
    #Handlers/RemoveAllHandler.h
    #Handlers/PrintHandler.cpp
    #Handlers/PrintHandler.h
    #Handlers/RemoveHandler.cpp
    #Handlers/RemoveHandler.h
    #Handlers/ClearHandler.cpp
    #Handlers/ClearHandler.h
    #Handlers/CreateDefHandler.cpp
    #Handlers/CreateDefHandler.h
    #Handlers/ChangeSizeHandler.cpp
    #Handlers/ChangeSizeHandler.h
    #Handlers/SetNameHandler.cpp
    #Handlers/SetNameHandler.h
    #Handlers/SetValueHandler.cpp
    #Handlers/SetValueHandler.h
    #Handlers/GetNameHandler.cpp
    #Handlers/GetNameHandler.h
    #Handlers/GetSizeHandler.cpp
    #Handlers/GetSizeHandler.h
    #Handlers/GetValueHandler.cpp
    #Handlers/GetValueHandler.h
    #Handlers/HelpHandler.cpp
    #Handlers/HelpHandler.h
)

set(ELEMENTS_AND_TABLES
    ElementsAndTables/CTable.hpp
    ElementsAndTables/RAII.hpp
    ElementsAndTables/ARRAII.hpp
	ElementsAndTables/Person.hpp
	ElementsAndTables/Person.cpp
)

set(UTILS
    Utils/Interface.cpp
    Utils/Interface.hpp
    Utils/Logger.cpp
    Utils/Logger.hpp
    #Utils/Stub.cpp
    #Utils/Stub.hpp
    Utils/Utils.cpp
    Utils/Utils.hpp
    #Utils/UtilsForMT.cpp
    #Utils/UtilsForMT.h
)

set(MT_UT
    #MT_UT/FlyweightProperAmountOfArgsButWrongMT.cpp
    #MT_UT/FlyweightProperArgsMT.cpp
    #MT_UT/FlyweightUnproperAmountOfArgsMT.cpp
    #MT_UT/List1.cpp
    MT_UT/TableUT.cpp
    MT_UT/PersonUT.cpp
    MT_UT/RAII_ARRAII_UT.cpp
)

set(FLYWEIGHT
    Flyweight/Flyweight.cpp
    Flyweight/Flyweight.hpp
)

source_group("MT_UT" FILES ${MT_UT})
source_group("Utils" FILES ${UTILS})
source_group("Flyweight" FILES ${FLYWEIGHT})
source_group("Handlers" FILES ${HANDLERS})
source_group("ElementsAndTables" FILES ${ELEMENTS_AND_TABLES})

add_executable(${PROJECT_NAME} MetaTablesRunner.cpp
    ${HANDLERS}
    ${ELEMENTS_AND_TABLES}
    ${UTILS}
    ${MT_UT}
    ${FLYWEIGHT}
)

add_dependencies(${PROJECT_NAME} gtest_main)
target_link_libraries(${PROJECT_NAME} gtest_main gtest)
