#include "slim/core/system.h"
#include "slim/window/WindowImplementation.hh"

#if SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_LINUX || SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_FREEBSD
# include "linux/WindowImplementation.cpp"
#elif SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_WINDOWS
# include "win32/WindowImplementation.cpp"
#else
# error "WindowImplementation not implemented yet for this system."
#endif
