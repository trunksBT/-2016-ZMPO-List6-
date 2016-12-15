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
    CTable(int inSize, int inInitVal);
    CTable(int inSize, std::string inName);
    ~CTable();
    void copyCtor(CTable & inVal);
    CTable& operator=(CTable& inObj);
    CTable* clone();
public:
    int getSize() const;
    int getVal(int inIdx) const;
    std::string getName() const;
    std::string toString() const;
public:
    void setSize(int inNewSize);
    void setName(std::string inName);
    void setVal(int idx, int inNewVal);
public:
    static CTable* buildNewObj();
    static CTable* buildNewObj(CTable & inVal);
    static CTable* buildNewObj(int inSize);
    static CTable* buildNewObj(int inSize, std::string inName);
    static CTable* buildNewObj(int inSize, int inInitValue);
    void initTable(int* inTable, int inSize, int inDefaultVal);
    void initTable();

private:
    void deepCopy(CTable& inVal);
    void allocateMemory(int inSize);
    void deallocateMemory();
private:
    std::string name_;
    int* memory_;
    int size_;
};
