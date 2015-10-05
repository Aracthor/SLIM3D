#ifndef SLIM_EVENTS_MOUSE_HH_
# define SLIM_EVENTS_MOUSE_HH_

# include "slim/core/system.h"

# if SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_LINUX || SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_FREEBSD
#  include "linux/mouse.hh"
# elif SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_WINDOWS
#  include "win32/mouse.hh"
# else
#  error "mouse not implemented yet for this system."
# endif

#endif // !SLIM_EVENTS_MOUSE_HH_
