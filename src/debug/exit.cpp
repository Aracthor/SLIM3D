#include <iostream>

#include "slim/debug/exit.hh"

#include <unistd.h>

namespace slim
{
namespace debug
{

void
exit(const char* message)
{
    std::cerr << message << std::endl;
    ::_exit(1);
}

void
debugExit(const char* message, const char* file, int line)
{
    std::cerr << file << ':' << std::endl
	      << "Line " << line << ':' << std::endl
	      << "Fatal error: " << message << std::endl;
    ::_exit(1);
}

}
}
