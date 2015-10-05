#ifndef SLIM_WINDOW_WINDOW_IMPLEMENTATION_HH_
# define SLIM_WINDOW_WINDOW_IMPLEMENTATION_HH_

# include "slim/core/system.h"
# include "slim/window/Window.hh"

# if SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_LINUX || SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_FREEBSD
#  include "linux/WindowImplementation.hh"
# elif SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_WINDOWS
#  include "win32/WindowImplementation.hh"
# else
#  error "WindowImplementation not implemented yet for this system."
# endif

#endif // !SLIM_WINDOW_WINDOW_IMPLEMENTATION_HH_
