#include "slim/io/UnbufferedReadingFile.hpp"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/UnbufferedReadingFile.cpp"
#else
# include "win32/UnbufferedReadingFile.cpp"
#endif
