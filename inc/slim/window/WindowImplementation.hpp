#ifndef SLIM_WINDOW_WINDOW_IMPLEMENTATION_HPP_
# define SLIM_WINDOW_WINDOW_IMPLEMENTATION_HPP_

# include "slim/system.h"
# include "slim/window/Window.hpp"

# if SLIM_SYSTEM == SLIM_SYSTEM_LINUX || SLIM_SYSTEM == SLIM_SYSTEM_FREEBSD
#  include "linux/WindowImplementation.hpp"
# elif SLIM_SYSTEM == SLIM_SYSTEM_WINDOWS
#  include "win32/WindowImplementation.hpp"
# else
#  error "WindowImplementation not implemented yet for this system."
# endif

#endif // !SLIM_WINDOW_WINDOW_IMPLEMENTATION_HPP_
