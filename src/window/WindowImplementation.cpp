#include "slim/system.h"
#include "slim/window/WindowImplementation.hpp"

#if SLIM_SYSTEM == SLIM_SYSTEM_LINUX || SLIM_SYSTEM == SLIM_SYSTEM_FREEBSD
# include "linux/WindowImplementation.cpp"
#elif SLIM_SYSTEM == SLIM_SYSTEM_WINDOWS
# include "win32/WindowImplementation.cpp"
#else
# error "WindowImplementation not implemented yet for this system."
#endif
