#pragma once

#include <iostream>
#include <string>
#include <ElementsAndTables/RAII.hpp>

class CPerson
{
public:
    explicit CPerson(int inAge) noexcept;
    CPerson(std::string inSurname, unsigned int inAge) noexcept;
    CPerson(const CPerson& inObj) noexcept;
    CPerson(CPerson&& inObj) noexcept;
    CPerson& operator=(CPerson&& inObj) noexcept;
    CPerson& operator=(const CPerson& inObj) noexcept;
    ~CPerson() noexcept;

    void swap(CPerson& first, CPerson& second) noexcept;

    bool operator==(const CPerson& inObj) const noexcept;
    explicit operator std::string() const noexcept;

    std::string getName() const noexcept;

    friend std::ostream& operator<<(std::ostream& stream, const CPerson& inVal)
    {
        stream << static_cast<std::string>(inVal);
        return stream;
    }
private:
    RAII<std::string> surname_;
    unsigned int age_;
};
