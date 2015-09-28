#ifndef SLIM_CONTEXT_CONTEXT_IMPLEMENTATION_HH_
# define SLIM_CONTEXT_CONTEXT_IMPLEMENTATION_HH_

# include "slim/context/IContextImplementation.hh"
# include "slim/core/system.h"

# if SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_LINUX || SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_FREEBSD
#  include "linux/ContextImplementation.hh"
# elif SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_WINDOWS
#  include "win32/ContextImplementation.hh"
# else
#  error "ContextImplementation not implemented yet for this system."
# endif

#endif // !SLIM_CONTEXT_CONTEXT_IMPLEMENTATION_HH_
