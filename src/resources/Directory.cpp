#include "slim/resources/Directory.hh"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/Directory.cpp"
#elif SLIM_CORE_SYSTEM_IS_WINDOWS
# include "win32/Directory.cpp"
#endif // SLIM_CORE_SYSTEM_IS_WINDOWS
