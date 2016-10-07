#pragma once

#include <string>
#include <vector>

class CTable
{
public:
   CTable();
   CTable(int inSize);
   CTable(CTable& inVal);
   CTable(std::string inVal);
   ~CTable();
   void copyCtor(CTable & inVal);
   CTable& operator=(CTable& inObj);

public:
   int getSize() const;
   int getVal(int idx) const;
   std::string& getName();

public:
   void setName(std::string inName);
   void setVal(int idx, int newVal);
   void setSize(int inSize);

private:
   void allocateMemory(int inSize);
   void deallocateMemory();
   void copyMemory(CTable& inVal);

private:
   std::string name_;
   int* memory_;
   int size_;
};
