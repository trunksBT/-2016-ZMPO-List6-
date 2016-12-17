#include <iostream>
#include <algorithm>
#include <utility>

template <typename T>
class RAII
{
public:
    RAII(T* inVal):
        memory_(inVal)
    {
        std::cout << "RAII CTOR" << std::endl;
    }

    RAII(RAII&& inObj)
    {
        std::cout << "RAII MOVE CTOR" << std::endl;
        std::swap(memory_, inObj.memory_);
    }

    RAII& operator=(RAII&& inObj)
    {
        std::cout << "RAII MOVE=" << std::endl;
        std::swap(memory_, inObj.memory_);
        return *this;
    }

    RAII(const RAII& inObj):
        memory_(new T(*inObj.memory_))
    {
        std::cout << "RAII COPY_CTOR" << std::endl;
    }

    RAII& operator=(const RAII& inObj)
    {
        std::cout << "RAII COPY=" << std::endl;
        RAII temp = inObj;
        std::swap(memory_, temp.memory_);
        return *this;
    }

    bool operator==(const RAII& inObj) const noexcept
    {
        return *memory_ == *inObj.memory_;
    }

	~RAII()
	{
        std::cout << "RAII DTOR" << std::endl;
		delete memory_;
	}

    std::size_t size() const noexcept
    {
        return size_;
    }

    static void swap(RAII& leftObj, RAII& rightObj)
    {
        std::swap(leftObj.memory_, rightObj.memory_);
    }

private:
    T* memory_;
};
