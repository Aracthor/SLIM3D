#if SLIM_DEBUG_DEBUG_MODE
# define SLIM_DEBUG_WINDOWS_EXIT(message, ...)	slim::debug::windowsDebugExit(message, __FILE__, __func__, __LINE__, ## __VA_ARGS__)
#else
# define SLIM_DEBUG_WINDOWS_EXIT(message, ...)	slim::debug::windowsExit(message, ## __VA_ARGS__)
#endif

namespace slim
{
namespace debug
{

template <typename ...Args>
SLIM_CORE_NORETURN void	debugWindowsExit(const char* message, const char* file, const char* func, int line, Args&& ...args);
template <typename ...Args>
SLIM_CORE_NORETURN void	windowsExit(const char* message, Args&& ...args);

}
}

#include "exit.ipp"
