#ifndef SLIM_DEBUG_EXIT_HPP_
# define SLIM_DEBUG_EXIT_HPP_

# include "slim/attributes.h"
# include "slim/system.h"
# include "slim/debug/debug_modes.h"

# if SLIM_DEBUG_DEBUG_MODE
#  define SLIM_DEBUG_EXIT(message, ...)	slim::debug::debugExit(message, __FILE__, __LINE__, ## __VA_ARGS__)
# else
#  define SLIM_DEBUG_EXIT(message, ...)	slim::debug::exit(message, ## __VA_ARGS__)
# endif

namespace slim
{
namespace debug
{

SLIM_CORE_NORETURN void exitImplementation(int returnValue);

template <typename ...Args>
SLIM_CORE_NORETURN void	exit(const char* message, Args&& ...args);
template <typename ...Args>
SLIM_CORE_NORETURN void	debugExit(const char* message, const char* file, int line, Args&& ...args);

}
}

# if SLIM_SYSTEM_IS_WINDOWS
#  include "win32/exit.hpp"
# endif // SLIM_SYSTEM_IS_WINDOWS

# include "exit.ipp"

#endif // !SLIM_DEBUG_EXIT_HPP_
