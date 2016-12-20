#pragma once

#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <Utils/Utils.hpp>
#include <Utils/Logger.hpp>

using namespace defaultVals;
using namespace flags;

template <typename T>
class ARRAII
{
public:
    explicit ARRAII(int inSize = ONE) noexcept
    {
        size_ = inSize;
        allocateMemoryAndCallCtors();

        if (PRINT_ERRORS)
        {
            logger << "ARRAII CTOR" << POST_PRINT;
        }
    }

    ARRAII(ARRAII&& inObj) noexcept
    {
        if (PRINT_ERRORS)
        {
            logger << "ARRAII MOVE CTOR" << POST_PRINT;
        }
        swap(*this, inObj);
    }

    ARRAII& operator=(ARRAII&& inObj) noexcept
    {
        if (PRINT_ERRORS)
        {
            logger << "ARRAII MOVE=" << POST_PRINT;
        }
        swap(*this, inObj);
        return *this;
    }

    ARRAII(const ARRAII& inObj) noexcept
        : size_(inObj.size_)
    {
        memory_ = static_cast<T*>(malloc(size_ * sizeof(T)));

        for (int i = 0; i < size_; i++)
        {
            new(memory_ + i) T(inObj.memory_[i]);
        }

        if (PRINT_ERRORS)
        {
            logger << "ARRAII COPY_CTOR" << POST_PRINT;
        }
    }

    ARRAII& operator=(const ARRAII& inObj) noexcept
    {
        if (PRINT_ERRORS)
        {
            logger << "ARRAII COPY=" << POST_PRINT;
        }
        ARRAII temp = inObj;
        std::swap(memory_, temp.memory_);
        std::swap(size_, temp.size_);
        return *this;
    }

    bool operator==(const ARRAII& inObj) const noexcept
    {
        if (size_ != inObj.size_)
            return false;

        bool equalTables = true;
        for (int i = 0; i < size_; i++)
        {
            equalTables = memory_[i] == inObj.memory_[i];
        }
        return equalTables;
    }

	~ARRAII()
	{
        deallocateMemoryAndCallDtors();

        if (PRINT_ERRORS)
        {
            logger << "ARRAII DTOR" << POST_PRINT;
        }
	}

    T& operator[](int idx) const noexcept
    {
        return memory_[idx];
    }

    int size() const noexcept
    {
        return size_;
    }

    friend std::ostream& operator<< (std::ostream& stream, const ARRAII& inVal)
    {
        stream<<static_cast<std::string>(inVal);
        return stream;
    }

    explicit operator std::string() const noexcept
    {
        std::stringstream retVal;
        retVal << SQUARE_BRACKET_OPEN;

        for (int i = 0; i < size(); i++)
        {
            retVal << memory_[i] << COMMA_SPACE;
        }

        std::string stringedStream(retVal.str());
        std::string retTable = stringedStream.substr(ZERO, stringedStream.size() - TWO);
      
        return std::move(retTable + std::string(SQUARE_BRACKET_CLOSE));
    }

    static void swap(ARRAII& leftObj, ARRAII& rightObj) noexcept
    {
        std::swap(leftObj.memory_, rightObj.memory_);
        std::swap(leftObj.size_, rightObj.size_);
    }

    void allocateMemoryAndCallCtors() noexcept
    {
        memory_ = static_cast<T*>(malloc(size_ * sizeof(T)));

        for (int i = 0; i < size_; i++)
        {
            new(memory_ + i) T(size_);
        }
    }

    void deallocateMemoryAndCallDtors() noexcept
    {
        for (int i = 0; i < size_; i++)
        {
            (memory_ + i)->~T();
        }
        free(memory_);
    }

private:
    T* memory_ = nullptr;
    int size_ = int();
};
