#include "slim/io/UnbufferedWritingFile.hpp"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/UnbufferedWritingFile.cpp"
#else
# include "win32/UnbufferedWritingFile.cpp"
#endif

