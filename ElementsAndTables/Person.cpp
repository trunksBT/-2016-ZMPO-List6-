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

    RAII(const RAII&& inObj)
    {
        std::swap(memory_, inObj.memory_);
        std::swap(size_, inObj.size_);
    }

    RAII& operator=(RAII&& inObj)
    {
        std::cout << "RAII MOVE=" << std::endl;
        std::swap(memory_, inObj.memory_);
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
        RAII temp = inObj;
        swap(*this, temp);
        return *this;
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

    void swap(RAII& first, RAII& second)
    {
        using std::swap;
        swap(first.memory_, second.memory_);
    }

private:
    T* memory_;
    std::size_t size_;
};
