#include "slim/core/system.h"
#include "slim/io/UnbufferedFile.hh"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/UnbufferedFile.cpp"
#else
# include "win32/UnbufferedFile.cpp"
#endif
