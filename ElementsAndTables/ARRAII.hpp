#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <Utils/Utils.hpp>
#include <type_traits>

using namespace defaultVals;

template <typename T>
class ARRAII
{
public:
    ARRAII(size_t inSize)
        : size_(inSize)
    {
        memory_ = static_cast<T*>(malloc(size_ * sizeof(T)));

        for (int i = 0; i < size_; i++)
        {
            new(memory_ + i) T(size_);
        }
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII CTOR" << std::endl;
        }
    }

    ARRAII(ARRAII&& inObj)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII MOVE CTOR" << std::endl;
        }
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
    }

    ARRAII& operator=(ARRAII&& inObj)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII MOVE=" << std::endl;
        }
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
        return *this;
    }

    ARRAII(const ARRAII& inObj)
        : size_(inObj.size_)
    {
        for (int i = 0; i < size_; i++)
        {
            memory_ = new T(inObj.memory_[i]);
        }
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII COPY_CTOR" << std::endl;
        }
        std::copy(inObj.memory_, inObj.memory_ + inObj.size_, memory_);
    }

    ARRAII& operator=(const ARRAII& inObj)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII COPY=" << std::endl;
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
        for (int i = 0; i < size_; i++)
        {
            (memory_ + i)->~T();
        }
        free(memory_);

        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII DTOR" << std::endl;
        }
	}

    T& operator[](int idx) const noexcept
    {
        return memory_[idx];
    }

    std::size_t size() const noexcept
    {
        return size_;
    }

    friend std::ostream& operator<< (std::ostream& stream, const ARRAII& inVal)
    {
        stream<<static_cast<std::string>(inVal);
        return stream;
    }

    operator std::string() const noexcept
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

    static void swap(ARRAII& leftObj, ARRAII& rightObj)
    {
        std::swap(leftObj.memory_, rightObj.memory_);
        std::swap(leftObj.size_, rightObj.size_);
    }

private:
    T* memory_;
    std::size_t size_;
};
