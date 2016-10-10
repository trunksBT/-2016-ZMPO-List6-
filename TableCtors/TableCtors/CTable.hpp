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
    CTable(int inSize, std::string inName);
    ~CTable();
    void copyCtor(CTable & inVal);
    CTable& operator=(CTable& inObj);
    CTable* clone();
public:
    int getSize() const;
    int getVal(int idx) const;
    std::string getName() const;
    std::string toString() const;
public:
    void changeSize(int inNewSize);
    void setName(std::string inName);
    void setVal(int idx, int newVal);
public:
    static CTable* buildNewObj();
    static CTable* buildNewObj(CTable & inVal);
    static CTable* buildNewObj(int inSize);
    static CTable* buildNewObj(int inSize, std::string inName);
    static CTable* buildNewObj(int inSize, int inInitValue);

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
