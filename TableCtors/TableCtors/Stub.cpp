#include "stdafx.h"
#include "Stub.hpp"

namespace stub
{

std::vector<std::string> createDefm1 = { "createDef", "-1" };
std::vector<std::string> createDef0 = { "createDef", "0" };
std::vector<std::string> createDef6 = { "createDef", "6" };
std::vector<std::string> createDefsm1 = { "createDefs", "-1" };
std::vector<std::string> createDefs1 = { "createDefs", "1" };
std::vector<std::string> createDefs6 = { "createDefs", "6" };
std::vector<std::string> createDefs10 = { "createDefs", "10" };
std::vector<std::string> createDefs11 = { "createDefs", "11" };
std::vector<std::string> createDefs10000 = { "createDefs", "10000" };
std::vector<std::string> createCopy01 = { "createCopy", "0", "1" };
std::vector<std::string> createCopy06 = { "createCopy", "0", "6" };
std::vector<std::string> print0 = { "print", "0" };
std::vector<std::string> printm1 = { "print", "-1" };
std::vector<std::string> print6 = { "print", "6" };
std::vector<std::string> print10 = { "print", "10" };
std::vector<std::string> getNamem1 = { "getName", "-1" };
std::vector<std::string> getName0 = { "getName", "0" };
std::vector<std::string> getName6 = { "getName", "6" };
std::vector<std::string> getName10 = { "getName", "10" };
std::vector<std::string> getSizem1 = { "getSize", "-1" };
std::vector<std::string> getSize0 = { "getSize", "0" };
std::vector<std::string> getSize1 = { "getSize", "1" };
std::vector<std::string> getSize6 = { "getSize", "6" };
std::vector<std::string> getSize10 = { "getSize", "10" };
std::vector<std::string> removem1 = { "remove", "-1" };
std::vector<std::string> remove0 = { "remove", "0" };
std::vector<std::string> remove10 = { "remove", "10" };
std::vector<std::string> removeAll = { "removeAll" };
std::vector<std::string> setName0 = { "setName", "0", "newNameOfCTable" };
std::vector<std::string> setName6 = { "setName", "6", "newNameOfCTable" };
std::vector<std::string> setName10 = { "setName", "10", "newNameOfCTable" };
std::vector<std::string> getValue0_1 = { "getValue", "0", "1" };
std::vector<std::string> getValuem1_1 = { "getValue", "-1", "1" };
std::vector<std::string> getValue0_m1 = { "getValue", "0", "-1" };
std::vector<std::string> getValue1_2 = { "getValue", "1", "2" };
std::vector<std::string> getValue6_3 = { "getValue", "6", "3" };
std::vector<std::string> getValue10_10 = { "getValue", "10", "10" };
std::vector<std::string> setValue0_0_23 = { "setValue", "0", "0", "23" };
std::vector<std::string> setValue10_0_23 = { "setValue", "10", "0", "23" };
std::vector<std::string> setValue10_10_23 = { "setValue", "10", "10", "23" };
std::vector<std::string> setValuem1_m1_23 = { "setValue", "-1", "-1", "23" };
std::vector<std::string> setValue1_m1_23 = { "setValue", "1", "-1", "23" };

}

namespace wrongAmountStub
{

std::vector<std::string> createDef = { "createDef" };
std::vector<std::string> createDefs = { "createDefs" };
std::vector<std::string> createCopy0 = { "createCopy", "0" };
std::vector<std::string> print = { "print" };
std::vector<std::string> getName = { "getName" };
std::vector<std::string> getSize = { "getSize" };
std::vector<std::string> remove = { "remove" };
std::vector<std::string> removeAll = { "removeAll" };
std::vector<std::string> setName0 = { "setName", "0" };
std::vector<std::string> getValuem1 = { "getValue", "-1" };
std::vector<std::string> setValue0_0 = { "setValue", "0", "0" };
std::vector<std::string> wrongCommand = { "wrongCommand" };

}