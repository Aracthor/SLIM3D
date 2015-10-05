#include "slim/context/ContextImplementation.hh"
#include "slim/core/system.h"

#if SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_LINUX || SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_FREEBSD
# include "linux/ContextImplementation.cpp"
#elif SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_WINDOWS
# include "win32/ContextImplementation.cpp"
#else
# error "ContextImplementation not implemented yet for this system."
#endif
