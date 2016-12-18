// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <new>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <boost/optional.hpp>

class TempClass
{
public:
    int value;
    int value2;
    //int value;

    TempClass(int val)
        : value(val)
    {
        value = val;
        std::cout << "TEmp Class CTOR" << std::endl;
    }

    ~TempClass()
    {
        std::cout << "TEmp Class DTOR" << std::endl;
    }
};

template< typename T>
class ARRAII
{
private:
    T* x;
    int size;
public:
    ARRAII(int inVal)
        :size(inVal)
    {
        x = static_cast<T*>(malloc(size * sizeof(T)));

        for (int i = 0; i < size; i++)
        {
            new(x + i) T(3);
        }
        std::cout << std::endl;
        std::cout << "After CTOR ARRAII" << std::endl;

    }

    T& operator[](int idx)
    {
        return x[idx];
    }

    ~ARRAII()
    {
        for (int i = 0; i < size; i++)
        {
            (x + i)->~T();
        }
        free(x);
        std::cout << "After DTOR ARRAII" << std::endl;
    }
};

template <typename T>
class A
{
public:
    ARRAII<T> memory;
    int size;
    A(int inVal)
        :size(inVal)
        , memory(ARRAII<T>(inVal))
    {
        std::cout << "After CTOR A" << std::endl;

    }

    T& operator[](int idx)
    {
        return memory[idx];
    }

    ~A()
    {

        //free(x);
        //x = nullptr;
        std::cout << "After DTOR A" << std::endl;
    }
};

int main()
{

    //std::cout << b.x << std::endl;
    //b.x = new A<int>(10);
    //std::cout << b.x << std::endl;
    //return 0;
    {
        {
            {
                A<A<TempClass>> temp = A<A<TempClass>>(3);
                std::cout << temp[0][0].value << std::endl;
            }
            //std::cout << temp[0][1].value << std::endl;
        }
        {
            //TempClass* tempArray = new TempClass[10];
            //std::cout << tempArray << std::endl;
            //std::cout << tempArray + 1 << std::endl;
            //std::cout << tempArray+2 << std::endl;
            //delete[] tempArray;

            //double* tempArray2 = new double[10];
            //std::cout << tempArray2 << std::endl;
            //std::cout << tempArray2 + 1 << std::endl;
            //std::cout << tempArray2 + 2 << std::endl;
            //delete[] tempArray2;
        }
        //temp = ARRAII<int>(TempClass);

        //A<int> b(10);
        //int temp = b.x[0];
        //b.x[0] = 10;
        //std::cout << b.x[0] << std::endl;
        return 0;
    }
}
