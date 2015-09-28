#ifndef SLIM_EVENTS_KEYBOARD_HH_
# define SLIM_EVENTS_KEYBOARD_HH_

# include "slim/core/system.h"

# if SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_LINUX || SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_FREEBSD
#  include "linux/keyboard.hh"
# elif SLIM_CORE_SYSTEM == SLIM_CORE_SYSTEM_WINDOWS
#  include "win32/keyboard.hh"
# else
#  error "keyboard not implemented yet for this system."
# endif

#endif // !SLIM_EVENTS_KEYBOARD_HH_
