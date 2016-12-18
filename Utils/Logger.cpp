
#include "Logger.hpp"

using namespace flags;
Logger logger;

Logger::Logger()
{
    std::cout << "Logger CTOR" << std::endl;
}

Logger::~Logger()
{
    std::cout << "Logger DTOR" << std::endl;
}

Logger& Logger::operator<<(std::string inLog)
{
    std::cout << inLog;
    return logger;
}
