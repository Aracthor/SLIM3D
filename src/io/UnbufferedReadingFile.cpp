#include "slim/io/UnbufferedReadingFile.hh"

#if SLIM_CORE_SYSTEM_IS_UNIX
# include "unix/UnbufferedReadingFile.cpp"
#else
# include "win32/UnbufferedReadingFile.cpp"
#endif
