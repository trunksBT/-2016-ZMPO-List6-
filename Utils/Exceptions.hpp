#include <exception>

class OwnException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "OwnException";
    }
};

class IndexOutOfBoundsException : public OwnException
{
public:
    virtual const char* what() const throw()
    {
        return "IndexOutOfBoundsException";
    }
};

class InitialSizeLowerOrEqZero : public OwnException
{
public:
    virtual const char* what() const throw()
    {
        return "InitialSizeLowerOrEqZero";
    }
};