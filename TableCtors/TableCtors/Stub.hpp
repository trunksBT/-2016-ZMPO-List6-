#pragma once
#include <vector>
#include <string>
#include "CTable.hpp"

namespace stub
{

std::vector<std::string> createDef = { "createDef", "0" };
std::vector<std::string> createDefs0 = { "createDefs", "0" };
std::vector<std::string> createDefs4 = { "createDefs", "4" };
std::vector<std::string> createDefs20 = { "createDefs", "20" };

//createDef <nrTablicy> -wywo³uje domyœlny konstruktor obiektu o podanym numerze.
//
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

