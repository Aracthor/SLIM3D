#include "slim/system.h"
#include "slim/time/Sleeper.hpp"

#if SLIM_SYSTEM_IS_UNIX
# include "unix/Sleeper.cpp"
#else
# include "win32/Sleeper.cpp"
#endif
