#ifndef SLIM_DEBUG_EXIT_HH_
# define SLIM_DEBUG_EXIT_HH_

# include "slim/attributes.h"
# include "slim/debug/debug_modes.h"

# if SLIM_DEBUG_DEBUG_MODE
#  define SLIM_DEBUG_EXIT(message)	slim::debug::debugExit(message, __FILE__, __LINE__)
# else
#  define SLIM_DEBUG_EXIT(message)	slim::debug::exit(message)
# endif

namespace slim
{
namespace debug
{

SLIM_CORE_NORETURN void	exit(const char* message);
SLIM_CORE_NORETURN void	debugExit(const char* message, const char* file, int line);

}
}

#endif // !SLIM_DEBUG_EXIT_HH_
