#pragma once

namespace defaultVals
{
constexpr char* SEPARATOR = " ";
constexpr char* TABLE_NAME = "KORYTKO_TABLE";
constexpr char* POST_COPIED_NAME = "_copy";
constexpr char* DTOR_PRE_PRINT = "usuwam: ";
constexpr char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
constexpr char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
constexpr char* CTOR_ARG1_PRE_PRINT = "parametr: ";
constexpr char* POST_PRINT = "\n";

}

namespace idxOf
{
constexpr int command = 0;
constexpr int id = 1;
}

namespace messageLiterals
{
constexpr char* createDef = "createDef";
//createDef <nrTablicy> -wywo³uje domyœlny konstruktor obiektu o podanym numerze.
//create <nrTablicy> <rozmiar> <nazwaTablicy> -wywo³uje parametryczny kontruktor
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

