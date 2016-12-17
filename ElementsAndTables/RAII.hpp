#include <iostream>
#include <algorithm>
#include <utility>

template <typename T>
class RAII
{
public:
    RAII(size_t inSize)
        : size_(inSize)
        , memory_(new T[inSize])
    {
        init();
        std::cout << "RAII CTOR" << std::endl;
    }

    RAII(RAII&& inObj)
    {
        std::cout << "RAII MOVE CTOR" << std::endl;
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
    }

    RAII& operator=(RAII&& inObj)
    {
        std::cout << "RAII MOVE=" << std::endl;
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
        return *this;
    }

    RAII(const RAII& inObj)
        : size_(inObj.size_)
        , memory_(new T[inObj.size_])
    {
        std::cout << "RAII COPY_CTOR" << std::endl;
        std::copy(inObj.memory_, inObj.memory_ + inObj.size_, memory_);
    }

    RAII& operator=(const RAII& inObj)
    {
        std::cout << "RAII COPY=" << std::endl;
        RAII temp = inObj;
        std::swap(memory_, temp.memory_);
        std::swap(size_, temp.size_);
        return *this;
    }

    bool operator==(const RAII& inObj) const noexcept
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

	~RAII()
	{
        std::cout << "RAII DTOR" << std::endl;
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

    static void swap(RAII& leftObj, RAII& rightObj)
    {
        std::swap(leftObj.memory_, rightObj.memory_);
        std::swap(leftObj.size_, rightObj.size_);
    }

private:
    T* memory_;
    std::size_t size_;
};
