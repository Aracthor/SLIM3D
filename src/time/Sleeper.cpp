#include "slim/core/system.h"
#include "slim/time/Sleeper.hh"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/Sleeper.cpp"
#else
# include "win32/Sleeper.cpp"
#endif
