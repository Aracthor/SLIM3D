#include "slim/system.h"
#include "slim/debug/exit.hpp"
#include "slim/debug/LogManager.hpp"

namespace slim
{
namespace debug
{

void
exit::finalExit(int returnValue)
{
    LogManager::instance.destroy(); // Save log files/
    exitImplementation(returnValue);
}

}
}

#if SLIM_SYSTEM_IS_UNIX
# include "unix/exit.cpp"
#elif SLIM_SYSTEM_IS_WINDOWS
# include "win32/exit.cpp"
#else
# error "There is no slim::debug::exit definition for your system."
#endif
