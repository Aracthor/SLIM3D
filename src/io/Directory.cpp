#include "slim/io/Directory.hpp"

#if SLIM_SYSTEM_IS_UNIX
# include "unix/Directory.cpp"
#elif SLIM_SYSTEM_IS_WINDOWS
# include "win32/Directory.cpp"
#endif // SLIM_SYSTEM_IS_WINDOWS
