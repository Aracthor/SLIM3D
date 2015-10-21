#include <iostream>

namespace slim
{
namespace debug
{

// Single implementation in order to make stop the next function when there is no args left.
static inline void
printErrorMessage(const char* message)
{
    std::cerr << message;
}

template <typename ...Args>
static void
printErrorMessage(const char* message, Args&& ...args)
{
    std::cerr << message;
    printErrorMessage(args...);
}


template <typename ...Args>
void
exit::releaseExit(const char* message, Args&& ...args)
{
    std::cerr << "Fatal error: ";
    printErrorMessage(message, args...);
    std::cerr << std::endl;
    exitImplementation(1);
}

template <typename ...Args>
void
exit::debugExit(const char* message, const char* file, const char* func, int line, Args&& ...args)
{
    std::cerr << file << ':' << std::endl
	      << "Function " << func << ':' << std::endl
	      << "Line " << line << ':' << std::endl
	      << "Fatal error: ";
    printErrorMessage(message, args...);
    std::cerr << std::endl;
    exitImplementation(1);
}

}
}
