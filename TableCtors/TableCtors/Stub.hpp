#pragma once
#include <vector>
#include <string>
#include "CTable.hpp"

namespace stub
{

std::vector<std::string> createDef0 = { "createDef", "0" };
std::vector<std::string> createDef6 = { "createDef", "6" };
std::vector<std::string> createDefs1 = { "createDefs", "1" };
std::vector<std::string> createDefs6 = { "createDefs", "6" };
std::vector<std::string> createDefs10 = { "createDefs", "10" };
std::vector<std::string> createDefs10000 = { "createDefs", "10000" };
std::vector<std::string> getName0 = { "getName", "0" };
std::vector<std::string> getName10 = { "getName", "10" };
std::vector<std::string> getSize0 = { "getSize", "0" };
std::vector<std::string> getSize1 = { "getSize", "1" };
std::vector<std::string> getSize6 = { "getSize", "6" };
std::vector<std::string> getSize10 = { "getSize", "10" };
std::vector<std::string> remove0 = { "remove", "0" };
std::vector<std::string> remove10 = { "remove", "10" };
std::vector<std::string> removeAll = { "removeAll" };
std::vector<std::string> setName0 = { "setName", "0", "newNameOfCTable" };
std::vector<std::string> setName6 = { "setName", "6", "newNameOfCTable" };
std::vector<std::string> setName10 = { "setName", "10", "newNameOfCTable" };
std::vector<std::string> createCopy01 = { "createCopy", "0", "1" };
std::vector<std::string> createCopy06 = { "createCopy", "0", "6" };
//createCopy <nrTablicy> <nrTablicyDoKopiowania> -wywo³uje kontruktor kopiuj¹cy


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
}

