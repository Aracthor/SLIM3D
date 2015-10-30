#ifndef SLIM_EVENTS_MOUSE_HPP_
# define SLIM_EVENTS_MOUSE_HPP_

# include "slim/system.h"

# if SLIM_SYSTEM == SLIM_SYSTEM_LINUX || SLIM_SYSTEM == SLIM_SYSTEM_FREEBSD
#  include "linux/mouse.hpp"
# elif SLIM_SYSTEM == SLIM_SYSTEM_WINDOWS
#  include "win32/mouse.hpp"
# else
#  error "mouse not implemented yet for this system."
# endif

#endif // !SLIM_EVENTS_MOUSE_HPP_
