#include "slim/system.h"
#include "slim/io/UnbufferedFile.hpp"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/UnbufferedFile.cpp"
#else
# include "win32/UnbufferedFile.cpp"
#endif
