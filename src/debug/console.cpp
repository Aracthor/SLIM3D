#include "slim/core/system.h"
#include "slim/debug/console.hh"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/console.cpp"
#elif SLIM_CORE_SYSTEM_IS_WINDOWS
# include "win32/console.cpp"
#else
# error "There is no slim::debug::console definition for your system."
#endif
