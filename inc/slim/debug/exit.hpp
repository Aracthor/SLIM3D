#ifndef SLIM_DEBUG_EXIT_HPP_
# define SLIM_DEBUG_EXIT_HPP_

# include "slim/attributes.h"
# include "slim/system.h"
# include "slim/debug/debug_modes.h"

# if SLIM_DEBUG_DEBUG_MODE
#  define SLIM_DEBUG_EXIT(message, ...)	slim::debug::exit::debugExit(message, __FILE__, __func__, __LINE__, ## __VA_ARGS__)
# else
#  define SLIM_DEBUG_EXIT(message, ...)	slim::debug::exit::releaseExit(message, ## __VA_ARGS__)
# endif

# define SLIM_DEBUG_MESSAGE_BUFFER_SIZE	0x1000

namespace slim
{
namespace debug
{

class	exit
{

public:
    template <typename ...Args>
    static SLIM_CORE_NORETURN void	releaseExit(const char* message, Args&& ...args);
    template <typename ...Args>
    static SLIM_CORE_NORETURN void	debugExit(const char* message, const char* file, const char* func, int line, Args&& ...args);

private:
    static SLIM_CORE_NORETURN void	exitImplementation(int returnValue);
    static SLIM_CORE_NORETURN void	finalExit(int returnValue);
};

}
}

# if SLIM_SYSTEM_IS_WINDOWS
#  include "win32/exit.hpp"
# endif // SLIM_SYSTEM_IS_WINDOWS

# include "exit.ipp"

#endif // !SLIM_DEBUG_EXIT_HPP_
