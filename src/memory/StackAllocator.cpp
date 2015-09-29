#include "slim/debug/debug_modes.h"
#include "slim/memory/StackAllocator.hh"

#if SLIM_DEBUG_MEMORY_MODE
# include "debug/StackAllocator.cpp"
#else
# include "release/StackAllocator.cpp"
#endif
