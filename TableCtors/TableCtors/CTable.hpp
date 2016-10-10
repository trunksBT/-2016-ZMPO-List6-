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
    CTable(int inSize, int initValue);
    ~CTable();
    void copyCtor(CTable & inVal);
    CTable& operator=(CTable& inObj);

public:
    int getSize() const;
    void changeSize(int inNewSize);
    int getVal(int idx) const;
    std::string getName() const;

public:
    void setName(std::string inName);
    void setVal(int idx, int newVal);

public:
    static CTable* buildNewObj();
    std::string toString();

private:
    void deepCopy(CTable& inVal);
    void initTable(int* table, int size, int defaultVal);
    void allocateMemory(int size);
    void deallocateMemory();

private:
    std::string name_;
    int* memory_;
    int size_;
};
