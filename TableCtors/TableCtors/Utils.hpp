#pragma once

#include <vector>
#include "CTable.hpp"

namespace funs
{
inline bool isProperIdx(int idxOrAmount, std::vector<CTable*>& inCache)
{
    return idxOrAmount < inCache.size() || idxOrAmount < 0;
}
}

namespace flags
{
constexpr bool printFlagOn = true;
}

namespace defaultVals
{
constexpr const char* PRE_PRINT = "   ";
constexpr const char* POST_PRINT = "\n";
constexpr const char* SEPARATOR = ": ";
constexpr const char* DEFAULT_TABLE_NAME = "KORYTKO_TABLE";
constexpr const char* POST_COPIED_NAME = "_copy";
constexpr const char* DTOR_PRE_PRINT = "usuwam: ";
constexpr const char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
constexpr const char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
constexpr const char* CTOR_DEFAULT_MOVE_PRINT = "przenoszenie: ";
constexpr const char* CTOR_ARG1_PRE_PRINT = "parametr: ";
constexpr int INITIAL_FLYWEIGHT_CACHE_SIZE = 5;
constexpr int ZERO = 0;
constexpr int FIVE = 5;
constexpr int DEFAULT_IN_TABLE_SIZE = 3;
constexpr const char* string999 = "999";
}

namespace logLiterals
{
constexpr const char* undefinedCommand = "Nie znam takiej komendy";
constexpr const char* undefinedObject = "Nie znam takiego obiektu";
constexpr const char* indexOutOfBound = "Index poza obszarem pamieci";
constexpr const char* nullPointerDetected = "Object";

}

namespace idxOf
{
constexpr int command = 0;
constexpr int id = 1;
constexpr int amount = 1;
constexpr int newName = 2;
constexpr int goalId = 2;
}

namespace messageLiterals
{
constexpr char* createDef = "createDef"; // calls default ctor for obj with number 
constexpr char* createDefs = "createDefs"; // calls default ctor for number of obj
constexpr char* getName = "getName"; // getName of CTable on idx
constexpr char* getSize = "getSize"; // getSize of CTable on idx
constexpr char* getValue = "getValue"; // getValue from table in CTable <nrTablicy> <nrPozycji>
constexpr char* remove = "remove"; // remove CTable on idx
constexpr char* removeAll = "removeAll"; // remove CTable on idx
constexpr char* setName = "setName"; // set name of CTable on idx
constexpr char* createCopy = "createCopy"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
                                           
                                     //createDef <nrTablicy> -wywo³uje domyœlny konstruktor obiektu o podanym numerze.
//create <nrTablicy> <rozmiar> <nazwaTablicy> -wywo³uje parametryczny kontruktor
//
//createDef <idx> -wywo³uje konstruktor na okreslonym indeksie
//
//createDefs <ilosc> -wywo³uje konstruktor okreslonej ilosci elementow
//
//createCopy <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy
//
//setValue <nrTablicy> <nrPozycji> <wartoœæ>
//
//getValue <nrTablicy> <nrPozycji>
//
//setName <nrTablicy> <nazwaTablicy>
//
//getName <nrTablicy>
}



