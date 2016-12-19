
#include "Logger.hpp"

Logger logger;

Logger::Logger()
{
    if (flags::PRINT_CTORS)
    {
        std::cout << "Logger CTOR" << std::endl;
    }
}

Logger::~Logger()
{
    if (flags::PRINT_CTORS)
    {
        std::cout << "Logger DTOR" << std::endl;
    }
}

Logger& Logger::operator<<(std::string inLog)
{
    std::cout << inLog;
    return logger;
}
