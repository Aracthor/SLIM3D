#ifndef SLIM_EVENTS_KEYBOARD_HPP_
# define SLIM_EVENTS_KEYBOARD_HPP_

# include "slim/system.h"

# if SLIM_SYSTEM == SLIM_SYSTEM_LINUX || SLIM_SYSTEM == SLIM_SYSTEM_FREEBSD
#  include "linux/keyboard.hpp"
# elif SLIM_SYSTEM == SLIM_SYSTEM_WINDOWS
#  include "win32/keyboard.hpp"
# else
#  error "keyboard not implemented yet for this system."
# endif

#endif // !SLIM_EVENTS_KEYBOARD_HPP_
