#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <Utils/Utils.hpp>
#include <type_traits>
#include <boost/optional.hpp>

using namespace defaultVals;

template <typename T>
class ARRAII
{
public:
    ARRAII(size_t inSize)
        : size_(inSize)
    {
        memory_ = new T[inSize];
        //init();
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
        std::swap(memory_.get(), inObj.memory_.get());
        std::swap(size_, inObj.size_);
    }

    ARRAII& operator=(ARRAII&& inObj)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII MOVE=" << std::endl;
        }
        std::swap(memory_.get(), inObj.memory_.get());
        std::swap(size_, inObj.size_);
        return *this;
    }

    ARRAII(const ARRAII& inObj)
        : size_(inObj.size_)

    {
        memory_ = new T[inObj.size_];
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII COPY_CTOR" << std::endl;
        }
        std::copy(inObj.memory_.get(), inObj.memory_.get() + inObj.size_, memory_.get());
    }

    ARRAII& operator=(const ARRAII& inObj)
    {
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII COPY=" << std::endl;
        }
        ARRAII temp = inObj;
        std::swap(memory_.get(), temp.memory_.get());
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
            equalTables = memory_.get()[i] == inObj.memory_.get()[i];
        }
        return equalTables;
    }

	~ARRAII()
	{
        if (flag::PRINT_ON)
        {
            std::cout << "ARRAII DTOR" << std::endl;
        }
		delete[] memory_.get();
	}

    T& operator[](int idx) const noexcept
    {
        return memory_.get()[idx];
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
            retVal << memory_.get()[i] << COMMA_SPACE;
        }

        std::string stringedStream(retVal.str());
        std::string retTable = stringedStream.substr(ZERO, stringedStream.size() - TWO);
      
        return std::move(retTable + std::string(SQUARE_BRACKET_CLOSE));
    }

    static void swap(ARRAII& leftObj, ARRAII& rightObj)
    {
        std::swap(leftObj.memory_.get(), rightObj.memory_.get());
        std::swap(leftObj.size_, rightObj.size_);
    }

private:
    boost::optional<T*> memory_;
    std::size_t size_;
};
