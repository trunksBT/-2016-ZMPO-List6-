#include <iostream>
#include <algorithm>
#include <utility>

template <typename T>
class ARRAII
{
public:
    ARRAII(size_t inSize)
        : size_(inSize)
        , memory_(new T[inSize])
    {
        init();
        std::cout << "ARRAII CTOR" << std::endl;
    }

    ARRAII(ARRAII&& inObj)
    {
        std::cout << "ARRAII MOVE CTOR" << std::endl;
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
    }

    ARRAII& operator=(ARRAII&& inObj)
    {
        std::cout << "ARRAII MOVE=" << std::endl;
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
        return *this;
    }

    ARRAII(const ARRAII& inObj)
        : size_(inObj.size_)
        , memory_(new T[inObj.size_])
    {
        std::cout << "ARRAII COPY_CTOR" << std::endl;
        std::copy(inObj.memory_, inObj.memory_ + inObj.size_, memory_);
    }

    ARRAII& operator=(const ARRAII& inObj)
    {
        std::cout << "ARRAII COPY=" << std::endl;
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
        std::cout << "ARRAII DTOR" << std::endl;
		delete[] memory_;
	}

    T& operator[](int idx) const noexcept
    {
        return memory_[idx];
    }

    std::size_t size() const noexcept
    {
        return size_;
    }

    void init()
    {
        for (int i = 0; i < size_; i++)
        {
            memory_[i] = T();
        }
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
