#include <iostream>
#include <algorithm>
#include <utility>
#include <Utils/Utils.hpp>

using namespace defaultVals;

template <typename T>
class RAII
{
public:
    explicit RAII(T inVal):
        memory_(new T(inVal))
    {
        if (PRINT_ERRORS)
        {
            logger << "RAII CTOR" << POST_PRINT;
        }
    }

    RAII(RAII&& inObj)
    {
        if (PRINT_ERRORS)
        {
            logger << "RAII MOVE CTOR" << POST_PRINT;
        }
        std::swap(memory_, inObj.memory_);
    }

    RAII& operator=(RAII&& inObj)
    {
        if (PRINT_ERRORS)
        {
            logger << "RAII MOVE=" << POST_PRINT;
        }
        std::swap(memory_, inObj.memory_);
        return *this;
    }

    RAII(const RAII& inObj):
        memory_(new T(*inObj.memory_))
    {
        if (PRINT_ERRORS)
        {
            logger << "RAII COPY_CTOR" << POST_PRINT;
        }
    }

    RAII& operator=(const RAII& inObj)
    {
        if (PRINT_ERRORS)
        {
            logger << "RAII COPY=" << POST_PRINT;
        }
        RAII temp = inObj;
        std::swap(memory_, temp.memory_);
        return *this;
    }

    bool operator==(const RAII& inObj) const noexcept
    {
        return *memory_ == *inObj.memory_;
    }

    explicit operator bool() const noexcept
    {
        return memory_ != nullptr;
    }

    T& operator*() const noexcept
    {
        return *memory_;
    }

	~RAII()
	{
        if (PRINT_ERRORS)
        {
            logger << "RAII DTOR" << POST_PRINT;
        }
		delete memory_;
	}

    static void swap(RAII& leftObj, RAII& rightObj) noexcept
    {
        std::swap(leftObj.memory_, rightObj.memory_);
    }

private:
    T* memory_ = nullptr;
};
