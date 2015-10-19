#include "slim/system.h"

#if SLIM_SYSTEM_IS_UNIX
# include "unix/exit.cpp"
#elif SLIM_SYSTEM_IS_WINDOWS
# include "win32/exit.cpp"
#else
# error "There is no slim::debug::exit definition for your system."
#endif
